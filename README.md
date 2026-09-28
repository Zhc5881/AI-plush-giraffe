# AI-plush-giraffe
![](https://github.com/rkuo2000/AI-plush-giraffe/blob/main/assets/plush_toy_giraffe.webp?raw=true)

---
## System HW & SW specifications

### System Block Diagram
![](https://github.com/rkuo2000/AI-plush-giraffe/blob/main/assets/AI-plush-toy_block_diagram.png?raw=true)

### LLM + Agent
`gemma4:e2b` based on [Goole-AI-Edge Gallery](https://github.com/google-ai-edge/gallery) v1.0.19 <br>

### Hardware : 
1. EVB : AMB82-Mini (built-in camera & mic)
2. Sound : PAM8403 + speaker

---
## Prompts: `ChatGPT`
```
Google Edge AI Gallery App support MCP and Skills, what would be recommended code to run on AMB82-mini to host on the plush toy Giraffe
```

---
## [Proposal](https://github.com/rkuo2000/AI-plush-giraffe/blob/main/PROPOSAL.md)
```text
                   SMART GIRAFFE
 ┌────────────────────────────────────────────┐
 │                AMB82-Mini                  │
 │                                            │
 │ Camera ──> local vision ──> perception     │
 │ Mic ─────> audio/event detection           │
 │                                            │
 │              Giraffe Agent API             │
 │        HTTP/WebSocket JSON interface       │
 │                    │                       │
 │       ┌────────────┼────────────┐          │
 │       ▼            ▼            ▼          │
 │    Speaker       Servos        LEDs        │
 │   / playback   head / ears   expression    │
 └────────────────────┬───────────────────────┘
                      │ Wi-Fi
                      │
              Android phone/tablet
 ┌────────────────────▼───────────────────────┐
 │          Google AI Edge Gallery            │
 │                                            │
 │        on-device model / agent             │
 │                 │                          │
 │         Giraffe Agent Skill                │
 │                 │                          │
 │        JS Skill / MCP ecosystem            │
 │                 │                          │
 │       ┌─────────┼─────────┐                │
 │       ▼         ▼         ▼                │
 │     look()    emotion()   move()           │
 │     status()  play()      etc.             │
 └────────────────────────────────────────────┘
```
### System Architecture Diagram
![](https://github.com/rkuo2000/AI-plush-giraffe/blob/main/assets/AI-plush-giraffe_architecture_diagram.png?raw=true)

---
## ProtoTyping

