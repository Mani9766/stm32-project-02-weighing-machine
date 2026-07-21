# High-Level Design (HLD)

**Project Name:** STM32 Project 02 – ADC-Based Weighing Machine

**Version:** 1.0

---

# 1. Introduction

This document describes the high-level software architecture of the ADC-Based Weighing Machine firmware.

The firmware is designed using a layered architecture to improve modularity, maintainability, and scalability. Each software layer has a well-defined responsibility and communicates only with adjacent layers.

---

# 2. Software Architecture

```text
+------------------------------------------------------+
|                  Application Layer                   |
|              main() / System Control                 |
+---------------------------+--------------------------+
                            |
                            ▼
+------------------------------------------------------+
|                  Service Layer                       |
|            Weighing Machine Service                  |
|                                                      |
|  - Read Sensor                                       |
|  - Convert ADC Count to Voltage                      |
|  - Calculate Weight                                  |
|  - Calibration                                       |
|  - Error Checking                                    |
+---------------------------+--------------------------+
                            |
                            ▼
+------------------------------------------------------+
|                   Driver Layer                       |
|                                                      |
|  ADC Driver           GPIO Driver                    |
+---------------------------+--------------------------+
                            |
                            ▼
+------------------------------------------------------+
|                    CMSIS Layer                       |
|         STM32 Register Definitions                   |
+---------------------------+--------------------------+
                            |
                            ▼
+------------------------------------------------------+
|                STM32F407 Hardware                    |
+------------------------------------------------------+
```

---

# 3. Software Modules

## 3.1 Application Layer

### Responsibilities

- System initialization
- Initialize firmware modules
- Execute the main application loop
- Call the Weighing Machine Service

---

## 3.2 Service Layer

### Responsibilities

- Acquire sensor data
- Convert ADC count into voltage
- Calculate weight
- Apply calibration
- Validate measurements
- Provide processed weight to the application

---

## 3.3 ADC Driver

### Responsibilities

- Initialize ADC peripheral
- Configure ADC channels
- Start ADC conversion
- Read ADC conversion result
- Stop ADC conversion

---

## 3.4 GPIO Driver

### Responsibilities

- Configure analog input pin
- Configure user button
- Configure status LEDs (future)

---

# 4. Layer Interaction

```text
Application
      │
      ▼
WeighingMachine_Service()
      │
      ▼
ADC_Read()
      │
      ▼
ADC Driver
      │
      ▼
ADC Hardware
```

Each layer communicates only with the layer immediately below it.

---

# 5. Design Principles

- Layered architecture
- Separation of concerns
- Modular software design
- Reusable drivers
- Low coupling
- High cohesion
- Maintainable firmware

---

# 6. Future Enhancements

The architecture supports future integration of:

- Digital filtering
- ADC Interrupt mode
- UART debugging
- External load cell
- External high-resolution ADC
- RTOS task integration

---
