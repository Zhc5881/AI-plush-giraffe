/*
 * GiraffeAgent.ino
 * AMB82-Mini smart-plush HTTP/JSON hardware API example.
 *
 * This sketch intentionally keeps AmebaNN, servo, LED and audio code behind
 * small adapter functions. Replace the TODO adapters with the corresponding
 * official AMB82-Mini examples for your board/core version.
 */

#include <WiFi.h>

// ---- Configuration ---------------------------------------------------------
const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const uint16_t HTTP_PORT = 8080;

WiFiServer server(HTTP_PORT);

enum Emotion { HAPPY, CURIOUS, THINKING, SLEEPY };
Emotion currentEmotion = HAPPY;

// ---- Hardware adapters -----------------------------------------------------
void initHardware() {
  // TODO: initialize LED, servo, audio and AmebaNN here.
  // Keep servo travel constrained in the implementation.
}

String visionJSON() {
  // TODO: replace with cached AmebaNN detection results.
  // Recommended starting point: official AmebaNN ObjectDetectionCallback.
  return "[{\"label\":\"person\",\"confidence\":0.94}]";
}

void nodHead() {
  // TODO: safe, limited servo sequence.
}

void shakeHead() {
  // TODO: safe, limited servo sequence.
}

void waveMotion() {
  // TODO: short expressive movement.
}

bool setEmotionByName(const String& name) {
  if (name == "happy") currentEmotion = HAPPY;
  else if (name == "curious") currentEmotion = CURIOUS;
  else if (name == "thinking") currentEmotion = THINKING;
  else if (name == "sleepy") currentEmotion = SLEEPY;
  else return false;

  // TODO: map emotion to RGB LED + small movement.
  return true;
}

bool playWhitelistedSound(const String& name) {
  // Keep file access whitelisted rather than accepting arbitrary paths.
  if (name != "hello" && name != "success" && name != "thinking") return false;
  // TODO: play /audio/<name> using your AMB82 audio implementation.
  return true;
}

// ---- HTTP helpers ----------------------------------------------------------
void sendJSON(WiFiClient& client, int code, const String& body) {
  client.print("HTTP/1.1 ");
  client.print(code);
  client.println(code == 200 ? " OK" : " Bad Request");
  client.println("Content-Type: application/json; charset=utf-8");
  client.println("Access-Control-Allow-Origin: *");
  client.println("Access-Control-Allow-Methods: GET, OPTIONS");
  client.println("Access-Control-Allow-Headers: Content-Type");
  client.println("Connection: close");
  client.println();
  client.println(body);
}

String requestPath(const String& requestLine) {
  int a = requestLine.indexOf(' ');
  if (a < 0) return "/";
  int b = requestLine.indexOf(' ', a + 1);
  if (b < 0) return "/";
  return requestLine.substring(a + 1, b);
}

String emotionName() {
  switch (currentEmotion) {
    case HAPPY: return "happy";
    case CURIOUS: return "curious";
    case THINKING: return "thinking";
    case SLEEPY: return "sleepy";
  }
  return "unknown";
}

void route(WiFiClient& client, const String& path) {
  if (path == "/api/status") {
    String json = "{\"ok\":true,\"device\":\"giraffe\",\"emotion\":\"";
    json += emotionName();
    json += "\",\"ip\":\"";
    json += WiFi.localIP().toString();
    json += "\"}";
    sendJSON(client, 200, json);
    return;
  }

  if (path == "/api/look") {
    sendJSON(client, 200, "{\"ok\":true,\"objects\":" + visionJSON() + "}");
    return;
  }

  if (path == "/api/nod") {
    nodHead();
    sendJSON(client, 200, "{\"ok\":true,\"action\":\"nod\"}");
    return;
  }

  if (path == "/api/shake") {
    shakeHead();
    sendJSON(client, 200, "{\"ok\":true,\"action\":\"shake\"}");
    return;
  }

  if (path == "/api/wave") {
    waveMotion();
    sendJSON(client, 200, "{\"ok\":true,\"action\":\"wave\"}");
    return;
  }

  const String emotionPrefix = "/api/emotion/";
  if (path.startsWith(emotionPrefix)) {
    String value = path.substring(emotionPrefix.length());
    if (!setEmotionByName(value)) {
      sendJSON(client, 400, "{\"ok\":false,\"error\":\"unsupported emotion\"}");
      return;
    }
    sendJSON(client, 200, "{\"ok\":true,\"emotion\":\"" + value + "\"}");
    return;
  }

  const String playPrefix = "/api/play/";
  if (path.startsWith(playPrefix)) {
    String value = path.substring(playPrefix.length());
    if (!playWhitelistedSound(value)) {
      sendJSON(client, 400, "{\"ok\":false,\"error\":\"unsupported sound\"}");
      return;
    }
    sendJSON(client, 200, "{\"ok\":true,\"sound\":\"" + value + "\"}");
    return;
  }

  sendJSON(client, 400, "{\"ok\":false,\"error\":\"unknown endpoint\"}");
}

void setup() {
  Serial.begin(115200);
  initHardware();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }

  Serial.println();
  Serial.print("Giraffe API: http://");
  Serial.print(WiFi.localIP());
  Serial.print(':');
  Serial.println(HTTP_PORT);

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  client.setTimeout(1000);
  String requestLine = client.readStringUntil('\r');
  client.readStringUntil('\n');

  if (requestLine.startsWith("OPTIONS ")) {
    sendJSON(client, 200, "{\"ok\":true}");
  } else if (requestLine.startsWith("GET ")) {
    route(client, requestPath(requestLine));
  } else {
    sendJSON(client, 400, "{\"ok\":false,\"error\":\"GET only\"}");
  }

  delay(1);
  client.stop();
}
