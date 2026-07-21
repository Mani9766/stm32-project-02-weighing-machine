# Software Requirements Specification (SRS)

**Project Name:** STM32 Project 02 – ADC-Based Weighing Machine

**Version:** 1.0

**Author:** Manisha Daigavhane

**Date:** 21-07-2026

---

# 1. Introduction

## 1.1 Purpose

The purpose of this project is to design and develop a bare-metal firmware application for an ADC-based weighing machine using the STM32F407 Discovery Board.

The project aims to provide a practical understanding of STM32 ADC peripheral programming by implementing a real-world embedded application instead of isolated peripheral examples.

The firmware will be developed using CMSIS register-level programming and a modular software architecture.

---

## 1.2 Scope

The project demonstrates how analog data acquired through the STM32 ADC peripheral can be converted into meaningful weight information.

The firmware will include:

- GPIO Driver
- ADC Driver
- Weight Calculation Module
- Calibration Module
- Error Handling
- Modular Application Layer

The project is intended for learning and demonstration purposes and is not intended for commercial weighing systems.

---

# 2. System Overview

The system periodically acquires an analog signal using the STM32 ADC.

The acquired digital value is converted into voltage, calibrated, and processed to estimate the corresponding weight.

Initially, the internal temperature sensor will be used only for ADC driver validation.

The application architecture is designed such that the analog input source can later be replaced by an external weight sensor without modifying the application layer.

---

# 3. Functional Requirements

## FR-01

The firmware shall initialize the STM32 ADC peripheral.

## FR-02

The firmware shall configure the required GPIO pins for analog operation.

## FR-03

The firmware shall perform ADC conversion using polling mode.

## FR-04

The firmware shall read the converted ADC value.

## FR-05

The firmware shall convert the ADC count into its corresponding voltage.

## FR-06

The firmware shall calculate the estimated weight using a calibration equation.

## FR-07

The firmware shall detect invalid ADC readings.

## FR-08

The firmware shall support future software enhancements without requiring modifications to the application layer.

# 4. Non-Functional Requirements

The firmware shall:

- Follow modular software architecture.
- Be easy to maintain.
- Be reusable across applications.
- Use CMSIS register-level programming.
- Minimize CPU utilization where possible.
- Be well documented.

---

# 5. Hardware Requirements

| Component | Description |
|-----------|-------------|
| MCU | STM32F407VG |
| Development Board | STM32F407 Discovery |
| ADC | ADC1 |
| Programming Language | Embedded C |
| IDE | STM32CubeIDE |
| Debugger | ST-Link |

---

# 6. Software Requirements

- STM32CubeIDE
- CMSIS Device Headers
- Git
- GitHub

---

# 7. Assumptions

- The project uses the STM32 internal ADC for firmware development.
- The internal temperature sensor is used only for ADC validation.
- The weighing sensor is represented by a generic analog voltage source during software development.
- Calibration constants are predefined.

---

# 8. Constraints

- ADC resolution is limited to 12 bits.
- Polling mode is used in the initial implementation.
- The project targets the STM32F407 Discovery Board.

---

# 9. Future Enhancements

- Interrupt-driven ADC conversion
- Digital filtering
- External load cell integration
- External high-resolution ADC interface
- UART debugging support

---

# 10. Acceptance Criteria

The project shall be considered complete when:

- ADC initialization is successful.
- ADC conversions produce valid digital values.
- Voltage conversion is verified.
- Weight calculation is validated.
- The firmware operates continuously without errors.
- All planned documentation is completed.

---
