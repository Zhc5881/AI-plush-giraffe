# AMB82-Mini + Google AI Edge Gallery Smart Giraffe

## Proposal

Build the plush giraffe as an embodied AI peripheral. The AMB82-Mini handles deterministic hardware functions—camera inference, sensors, LEDs, audio playback, and limited servo motion—while Google AI Edge Gallery on an Android device handles language reasoning and Agent Skills.

## Architecture

```text
World -> AMB82-Mini -> Wi-Fi JSON API -> AI Edge Gallery / Gemma
          |                                |
          + camera / YOLO                  + Agent Skill
          + microphone/events              + planning
          + LEDs                           + conversation
          + speaker
          + servos
```

### Design rule
Keep the hardware boundary simple. The first version should expose a compact HTTP/JSON API rather than implementing a full MCP server on the microcontroller. AI Edge Gallery can use a JavaScript Skill as the bridge. MCP can remain at the Android/agent layer when integration with additional services is useful.

## Recommended semantic tools

- `status()` — report device state.
- `look()` — return latest local vision detections.
- `nod()` — small head nod.
- `shake()` — small head shake.
- `wave()` — short expressive motion.
- `emotion(value)` — set LED/motion expression: `happy`, `curious`, `thinking`, `sleepy`.
- `play(name)` — play a whitelisted sound stored on the device.

The LLM should never command raw PWM values. Firmware owns motion limits and validates all commands.

## Local AI

Start with AMB82-Mini object detection using AmebaNN and YOLOv7-tiny. The firmware adapter in this repository is intentionally isolated so the official `ObjectDetectionCallback`/`ObjectDetectionLoop` example can be integrated without changing the network API.

## AI Edge Gallery Skill

The `giraffe-companion` skill follows AI Edge Gallery's current JavaScript Skill structure:

```text
giraffe-companion/
├── SKILL.md
└── scripts/
    └── index.html
```

`SKILL.md` tells the model when and how to invoke `run_js`. `scripts/index.html` exposes `window.ai_edge_gallery_get_result`, parses the model-provided JSON, calls the AMB82 HTTP API with `fetch()`, and returns a JSON string containing `result` or `error`.

## Event-driven V2

After HTTP control is stable, add an event channel for events such as `person_detected`, `button_pressed`, or `gesture_detected`. Keep continuous camera frames local; send compact semantic events to the agent.

## Prototype phases

1. Wi-Fi + `/api/status`.
2. LEDs + safe head motion.
3. Local object detection + `/api/look`.
4. microSD sound playback.
5. AI Edge Gallery JS Skill.
6. Audio input/output integration.
7. Event-driven agent behavior.

## Safety and privacy

- Use conservative servo limits and an internal rigid mount.
- Do not expose batteries, wiring, or moving mechanisms through the plush exterior.
- Avoid continuous remote audio/video upload; perform local perception where possible.
- Make camera/microphone activity visible to the user.
- Do not store network credentials or API secrets in a public repository.
- Treat the modified plush as an engineering prototype, not a certified children's product.
