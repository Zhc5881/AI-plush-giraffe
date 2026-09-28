# Giraffe AI Plush

Example starter repository for an AMB82-Mini smart plush controlled by a Google AI Edge Gallery JavaScript Agent Skill.

## Layout

```text
.
├── PROPOSAL.md
├── README.md
├── firmware/
│   └── GiraffeAgent/
│       └── GiraffeAgent.ino
└── giraffe-companion/
    ├── SKILL.md
    └── scripts/
        └── index.html
```

## Quick start

1. Open `firmware/GiraffeAgent/GiraffeAgent.ino` in the Arduino IDE configured for AMB82-Mini.
2. Enter the development Wi-Fi credentials, compile, upload, and read the board IP from Serial Monitor.
3. Confirm `http://<board-ip>:8080/api/status` is reachable from the Android device on the same trusted LAN.
4. Put that IP in `giraffe-companion/scripts/index.html` as `GIRAFFE_BASE_URL`.
5. Import the `giraffe-companion` folder as a local Agent Skill in Google AI Edge Gallery, or host it on a web host that serves the files with executable MIME types.
6. Ask the Agent Skills model to check the giraffe status, look around, nod, wave, or change expression.

## AMB82 AI integration

`visionJSON()` currently returns demo data. Replace it with the result cache from the official AmebaNN object-detection example. AMB82-Mini documentation supports object detection tasks and YOLOv3-tiny, YOLOv4-tiny, and YOLOv7-tiny model selections. Customized models can also be loaded from SD card.

Keep the networking layer independent from the NN callback: update a small cached detection list from the inference callback and serialize that cache when `/api/look` is requested.

## Production improvements

- DHCP reservation or local discovery instead of a hard-coded IP.
- Authentication between the phone and toy.
- POST endpoints for state-changing operations.
- Rate limiting and a command queue for motion.
- Physical camera/microphone enable switch or visible activity indicator.
- Proper audio driver and microSD sound implementation.
- Event channel after the request/response prototype is stable.

## Notes

The example intentionally does not accept raw servo positions, arbitrary file paths, or arbitrary URLs from the model. The firmware remains the authority for safe hardware limits.
