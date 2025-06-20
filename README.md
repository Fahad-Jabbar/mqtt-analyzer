# MQTT Explorer – A Lightweight Qt-Based MQTT Client

**MQTT Explorer** is a lightweight, cross-platform graphical tool built using the Qt framework for exploring and debugging MQTT (Message Queuing Telemetry Transport) communication. It enables users to connect to MQTT brokers, visualize topic hierarchies, publish/subscribe to topics, and interact with real-time data in an intuitive interface.

This tool is ideal for IoT developers, QA engineers, and anyone dealing with pub/sub systems using MQTT protocol.

---

## Features

- Connect to any MQTT broker with customizable address and credentials
- Subscribe to topics (supports wildcards) and receive real-time messages
- Topic hierarchy visualization in tree format
- Publish messages with:
  - Payload (text/JSON)
  - QoS level selection (0, 1, 2)
  - Retain flag
- Add interactive widgets for devices like thermostats, lights, displays
- Load and save dashboard configurations
- Clean and responsive UI (supports Linux, Windows, macOS)
- No heavy dependencies – fast and offline-friendly

---

## GUI Preview

![Dashboard Interface](https://github.com/Fahad-Jabbar/mqtt-analyzer/blob/main/Dashboard.png)

> *Example of a custom dashboard with interactive widgets for IoT devices like thermostats, lights, displays, and cameras.*

---

## 📦 Dependencies

To build and run the project, ensure you have:

- **Qt 5.x or 6.x** (Install with Qt Creator for ease)
- `qmake` – Qt’s build system tool
- `make` – GNU Make or equivalent
- A C++ compiler (GCC, Clang, MSVC)
- An MQTT broker (e.g., [Mosquitto](https://mosquitto.org/), HiveMQ, EMQX)

---

## Project Structure

**mqtt-explorer/**
- `src/` – Source code (.cpp and .h files)  
- `examples/` – Sample configurations or topic data  
- `Resources.qrc` – Qt resource file (icons/images)  
- `demo_*.gif` – UI demo animations (optional)  
- `Project.pro` – Qt project file  
- `Makefile` – Manual Makefile  
- `README.md` – Project documentation

## Tips & Troubleshooting
- Broker not connecting? Ensure correct port (usually 1883) and that your broker allows external access.
- No messages received? Double-check the subscribed topic and whether the publisher is active.
- UI glitches? Try different Qt versions or styles if supported.

## Summary
MQTT Explorer provides a minimal yet powerful interface for MQTT debugging and interaction. With real-time message tracking, topic exploration, and widget-based dashboards, it's perfect for developers working in MQTT-enabled environments like smart homes, IoT devices, and embedded systems.



