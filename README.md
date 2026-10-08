:::writing{variant="document" id="42617" title="README.md"}

##AI Agent RoboCar
An embodied AI robot powered by AMB82-Mini and Gemma4-E2B.

##Project Overview
This project aims to develop an AI Agent RoboCar that can understand natural-language commands, perceive its environment, plan tasks, and perform physical actions.

The AMB82-Mini is used as the robot controller, handling the camera, microphone, IR distance sensor, IMU, motor driver, speaker, and other hardware.

Gemma4-E2B acts as the high-level AI agent responsible for natural-language understanding, visual reasoning, and task planning.

##System Architecture
                    User
                     │
          ┌──────────┴──────────┐
          │                     │
      Voice Input          Edge AI App
          │                     │
          └──────────┬──────────┘
                     │
                     ▼
              Gemma4-E2B
               AI Agent
                     │
            Task / Tool Commands
                     │
                     ▼
              AMB82-Mini
            Robot Controller
                     │
       ┌─────────────┼─────────────┐
       │             │             │
     Camera       IR Sensor       IMU
       │             │             │
       └─────────────┼─────────────┘
                     │
               Motor Driver
                     │
                     ▼
                  RoboCar
                     │
                     ▼
                Speaker / TTS

##Main Features
Natural-language interaction
Voice interaction with the RoboCar
Edge AI App interaction
Camera-based visual perception
AI task planning
Autonomous movement
IR obstacle detection
IMU motion sensing
TTS voice response
Semantic robot control

##Example
The user says:

"Find the red cup."
The AI Agent will:

Understand the user's goal.
Use the camera to observe the environment.
Plan appropriate robot actions.
Control the RoboCar through AMB82-Mini.
Use the IR sensor to detect obstacles.
Continue searching for the target.
Stop when the target is found.
Report the result using TTS.
User
 ↓
"Find the red cup."
 ↓
Gemma4-E2B
 ↓
Task planning
 ↓
Camera perception
 ↓
Robot movement
 ↓
Obstacle detection
 ↓
Target found
 ↓
TTS response

##Hardware
Component	Function
AMB82-Mini	Robot controller
Camera	Visual perception
Microphone	Voice input
Speaker	Voice output
IR Distance Sensor	Obstacle detection
IMU	Motion and orientation sensing
Motor Driver	Wheel control
SD Card	Audio and data storage
Two-wheel chassis	Robot movement

##AI Model
Gemma4-E2B

Gemma4-E2B provides the high-level intelligence for natural-language understanding, visual reasoning, and task planning.

The AMB82-Mini handles real-time sensing, motor control, and safety functions.

##Interaction Modes
1. Edge AI App
The user interacts with the AI Agent through an Android device.

The App can be used to:

Send text or voice commands.
Monitor the RoboCar.
View camera information.
Start AI tasks.
2. Direct Voice Interaction
The user can directly speak to the RoboCar.

User
 ↓
Microphone
 ↓
Gemma4-E2B
 ↓
AI Agent
 ↓
Robot Action
 ↓
Speaker / TTS

##Innovation
The main goal is to combine Edge AI, multimodal perception, AI Agent planning, and a physical robot.

Instead of simply controlling a robot using a remote controller, the RoboCar can understand a high-level goal and decide how to accomplish it.

The system demonstrates the complete embodied AI loop:

Perception → Reasoning → Planning → Action → Feedback

##Expected Results
The final prototype is expected to demonstrate:

Natural-language interaction
Camera-based perception
AI task planning
Autonomous robot movement
Obstacle avoidance
Voice response
Edge AI App interaction
Direct voice interaction

##Project Sketch
The planned RoboCar concept is shown below.

       ┌───────────────────────┐
       │      Gemma4-E2B       │
       │       AI Agent        │
       └───────────┬───────────┘
                   │
             Wi-Fi / Commands
                   │
       ┌───────────▼───────────┐
       │      AMB82-Mini       │
       │                       │
       │ Camera  Microphone    │
       │ IR Sensor  IMU        │
       │ Motor  Speaker        │
       └───────────┬───────────┘
                   │
                   ▼
             ┌───────────┐
             │  RoboCar  │
             └───────────┘

##Future Development
Future development may include:

More advanced object recognition
Multi-step autonomous missions
Improved navigation
Robot memory
Personalized user interaction
More complex visual reasoning

##Participation Statement
If participating in the Realtek technology program, this project will follow the relevant program requirements for development, testing, and demonstration. :::
