##Project proposal
The proposed project is an AI Agent RoboCar powered by the AMB82-Mini and Gemma4-E2B.

The AMB82-Mini acts as the robot's embedded hardware controller, handling the camera, microphone, IR distance sensor, IMU, motor driver, speaker, and local safety functions. Gemma4-E2B acts as the higher-level AI agent responsible for understanding natural-language commands, interpreting visual information, planning tasks, and deciding which robot actions should be performed.

The user can interact with the RoboCar in two ways:

Through an Edge AI App running on an Android device.
Directly by speaking to the RoboCar.
                         AI AGENT ROBOCAR

 ┌──────────────────────────────────────────────────┐
 │                 AMB82-Mini                      │
 │                                                 │
 │  Camera ───────> Visual perception              │
 │  Microphone ───> Voice input                    │
 │  IR Sensor ────> Obstacle detection             │
 │  IMU ──────────> Motion/orientation             │
 │                                                 │
 │  Motor Driver ─> Wheel movement                 │
 │  Speaker ──────> TTS / audio response           │
 │  SD Card ──────> Audio/data storage              │
 └──────────────────────┬──────────────────────────┘
                        │ Wi-Fi
                        │
              ┌─────────▼─────────┐
              │  Android Device   │
              │                   │
              │ Edge AI App       │
              │ Gemma4-E2B       │
              │ AI Agent          │
              └─────────┬─────────┘
                        │
                 Task / Tool Commands
                        │
                        ▼
                ┌───────────────┐
                │   RoboCar     │
                │ Move / Stop   │
                │ Turn / Search │
                │ Observe       │
                └───────────────┘

##Why use an AI Agent?
Traditional robot cars are usually controlled through buttons, joysticks, or predefined programs. The user must explicitly control each movement.

This project instead allows the user to describe a goal using natural language.

For example:

"Find the red cup."
The AI agent can interpret the goal, use the camera to understand the environment, select appropriate robot actions, and monitor the result.

The intended interaction loop is:

User instruction
       ↓
Gemma4-E2B
       ↓
Understand the task
       ↓
Plan high-level actions
       ↓
Robot action
       ↓
Camera / sensor feedback
       ↓
Re-plan if necessary
       ↓
Task completed
       ↓
TTS response
The language model should not directly control raw motor PWM values. Low-level motor control, sensor handling, and safety functions remain on the AMB82-Mini.

##Two-level robot architecture
       Cognitive / Agent Layer
       Android + Gemma4-E2B

       natural language understanding
       visual reasoning
       task planning
       high-level robot actions
       conversation
                │
                │
                ▼
       Embedded Control Layer
       AMB82-Mini

       camera
       microphone
       IR distance sensor
       IMU
       motor control
       audio playback
       safety control
This separation allows Gemma4-E2B to focus on reasoning while the AMB82-Mini handles deterministic and time-sensitive robot control.

##Recommended robot tools
The AI agent should interact with the RoboCar through a small set of semantic actions rather than unrestricted hardware commands.

robocar.look()
robocar.move_forward()
robocar.turn_left()
robocar.turn_right()
robocar.stop()
robocar.get_distance()
robocar.get_imu()
robocar.play_sound()
robocar.speak()
robocar.status()
Low-level commands such as raw PWM values, unrestricted GPIO control, or direct motor-driver registers should not be exposed to the AI agent.

##Main features
1. Natural-language interaction
The user can give instructions using normal language.

Examples:

"Go forward."

"Turn right."

"What do you see?"

"Find the red cup."

"Explore the room."
2. Vision-based perception
The camera provides visual information that can be used by the AI agent to understand the environment and identify objects.

For example:

User:
"Find the red cup."

       ↓

Camera captures the environment

       ↓

Gemma4-E2B analyzes the visual information

       ↓

Target object identified

       ↓

RoboCar moves toward the target
3. AI task planning
Gemma4-E2B is responsible for high-level task planning.

For example:

User:
"Find the red cup."

Agent:
1. Search the current area.
2. Move forward.
3. Check the camera view.
4. Avoid obstacles.
5. Change direction if necessary.
6. Stop when the red cup is found.
7. Report the result.
The AMB82-Mini executes the individual movement commands and provides sensor feedback.

4. Obstacle avoidance
The IR distance sensor is used for local obstacle detection.

Obstacle avoidance and emergency stopping should be handled locally by the AMB82-Mini rather than depending on the AI model.

IR sensor
    ↓
Obstacle detected
    ↓
AMB82-Mini
    ↓
Stop / avoid obstacle
This allows the RoboCar to react safely even when the AI agent is processing a task.

5. Voice interaction
The RoboCar includes a microphone and speaker.

The user can directly speak to the robot, while TTS allows the robot to respond naturally.

Example:

User:
"Can you find the red cup?"

       ↓

Gemma4-E2B

       ↓

RoboCar performs the search

       ↓

Speaker:
"I found the red cup!"
6. Edge AI App interaction
The Android Edge AI App provides an alternative interface for the user.

The App can be used to:

Send text or voice commands.
View camera information.
Monitor robot status.
Start or stop robot tasks.
Interact with the Gemma4-E2B agent.

##Example application: AI Object Search
One of the main demonstrations will be an AI object-search task.

User:
"Find the red cup."

        ↓

Gemma4-E2B
understands the task

        ↓

Camera
observes the environment

        ↓

AI Agent
selects robot actions

        ↓

AMB82-Mini
controls the motors

        ↓

IR Sensor
detects obstacles

        ↓

Camera
checks the environment again

        ↓

Target found

        ↓

RoboCar stops

        ↓

TTS:
"I found the red cup!"
This demonstrates the complete Agentic AI loop:

Perception → Reasoning → Planning → Action → Feedback

##Example application: AI Exploration
The user can also ask:

"Explore the room and tell me what you see."
The RoboCar can move through the environment while using the camera to observe objects and scenes.

The AI agent can then provide a natural-language description of what the robot has observed.

##Innovation
The main innovation of this project is the combination of:

Edge AI
Multimodal perception
Natural-language interaction
AI Agent task planning
Physical robot control
Instead of simply using AI as a chatbot or using the phone as a remote controller, the project gives the AI an embodied robot that can perceive its environment and perform physical actions.

The RoboCar therefore becomes an Embodied AI Agent capable of:

Seeing → Understanding → Planning → Acting → Reporting

##Hardware
AMB82-Mini
Camera
Microphone
Speaker
IR Distance Sensor
IMU
Two-wheel Motor Driver
Two-wheel Robot Chassis
SD Card

##AI Model
Gemma4-E2B

Gemma4-E2B is used as the high-level AI agent for natural-language understanding, visual reasoning, task planning, and generating responses.

The AMB82-Mini remains responsible for embedded sensing, real-time control, motor operation, and safety functions.

##Expected results
The expected final prototype will be able to:

Communicate with users using natural language.
Receive commands through direct voice interaction.
Receive commands through an Edge AI App.
Capture and analyze camera information.
Understand high-level tasks.
Plan a sequence of robot actions.
Move autonomously according to the planned task.
Detect and avoid obstacles using the IR sensor.
Respond to users using TTS.
Demonstrate a complete embodied AI agent workflow.

##Future development
Future versions may include:

More advanced object recognition.
Multi-step autonomous missions.
Improved navigation.
User-specific preferences.
Robot memory.
More complex visual reasoning.
Multi-robot cooperation.

##Safety and privacy
Emergency stop and basic obstacle avoidance should be handled locally by the AMB82-Mini.
Raw PWM and unrestricted GPIO control should not be exposed to the AI model.
Motor movement should have predefined speed and timeout limits.
Camera and microphone activity should be clearly indicated.
Audio and image data should not be stored by default unless required.
The robot should include a physical power switch.
Hardware and power connections should be validated before operation.

##Suggested implementation order
Bring up the AMB82-Mini and basic motor control.
Implement /status and basic sensor monitoring.
Implement IR obstacle detection and emergency stop.
Add camera capture.
Add microphone and audio playback.
Implement the RoboCar semantic action API.
Connect Gemma4-E2B through the Edge AI App.
Implement direct voice interaction.
Implement the AI object-search demonstration.
Add more advanced autonomous tasks.

##Repository layout
robocar-agent/
├── PROPOSAL.md
├── README.md
├── firmware/
├── app/
├── skills/
├── docs/
└── media/

##Participation Statement
If participating in the Realtek technology program, this project will follow the relevant program requirements for development, testing, and demonstration. :::
