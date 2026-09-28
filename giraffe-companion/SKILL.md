---
name: giraffe-companion
description: Observe and control a nearby AMB82-Mini smart giraffe plush through its local hardware API.
---

# Smart Giraffe Companion

Use this skill only when the user's request benefits from interacting with the physical giraffe.

## Instructions

Call the `run_js` tool with:

- script name: `index.html`
- data: a JSON string matching one of the schemas below.

### Device status

```json
{"action":"status"}
```

### Look at the surroundings

```json
{"action":"look"}
```

Use `look` only when visual information is relevant. Do not repeatedly capture or poll the camera without a reason.

### Head motion

```json
{"action":"nod"}
```

```json
{"action":"shake"}
```

```json
{"action":"wave"}
```

Use movements sparingly. The firmware enforces the physical limits.

### Expression

```json
{"action":"emotion","value":"happy"}
```

Allowed values are `happy`, `curious`, `thinking`, and `sleepy`.

### Play a stored sound

```json
{"action":"play","value":"hello"}
```

Allowed values are `hello`, `success`, and `thinking`.

## Behavior

- Prefer semantic actions instead of attempting low-level hardware control.
- Never invent a successful observation or hardware action. Use the returned result.
- If the device is unreachable, tell the user the giraffe is offline rather than repeatedly retrying.
- Avoid continuous camera or microphone capture.
