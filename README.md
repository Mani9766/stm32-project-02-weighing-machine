# stm32-project-02-weighing-machine

## Overview

This project demonstrates the development of an **ADC-based weighing machine** using the **STM32F407 Discovery Board**. The primary objective is to learn the STM32 ADC peripheral through a real-world embedded application while following a structured firmware development process.

The project is implemented using **CMSIS register-level programming** to provide a clear understanding of the STM32 ADC peripheral and firmware driver development.

---

## Objectives

- Learn STM32 ADC peripheral at the register level
- Develop reusable GPIO and ADC drivers
- Design a modular firmware architecture
- Convert ADC readings into weight values
- Implement software calibration
- Apply digital filtering for stable measurements
- Practice professional documentation and Git workflow

---

## Features

- Bare-metal STM32 firmware
- CMSIS register-level programming
- Modular driver architecture
- ADC polling
- Voltage conversion
- Weight calculation
- Software calibration
- Error handling
- Professional project documentation

---

## Hardware

| Component | Description |
|-----------|-------------|
| Microcontroller | STM32F407VG |
| Development Board | STM32F407 Discovery |
| IDE | STM32CubeIDE |
| Debugger | ST-Link |
| Programming Language | Embedded C |

---

## Software Architecture

```text
+------------------------+
|   Application Layer    |
+------------------------+
            │
            ▼
+------------------------+
|      Driver Layer      |
|   GPIO | ADC | ...     |
+------------------------+
            │
            ▼
+------------------------+
|         CMSIS          |
+------------------------+
            │
            ▼
+------------------------+
|    STM32F407 Hardware  |
+------------------------+
```

---

## Project Structure

```text
stm32-project-02-weighing-machine/
│
├── Docs/
│   ├── SRS.md
│   ├── HLD.md
│   ├── LLD.md
│   ├── Block_Diagram.md
│   ├── DFD.md
│   ├── Test_Plan.md
│   └── Interview_Notes.md
│
├── Images/
│
├── Firmware/
│   └── WeighingMachine/
│       ├── Core/
│       ├── Drivers/
│       ├── Startup/
│       ├── Debug/                 (Ignored by Git)
│       ├── .project
│       ├── .cproject
│       └── STM32F407VGTX_FLASH.ld
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## Development Roadmap

- [x] Create GitHub repository
- [x] Create README
- [ ] Software Requirements Specification (SRS)
- [ ] High-Level Design (HLD)
- [ ] Low-Level Design (LLD)
- [ ] System Block Diagram
- [ ] Data Flow Diagram (DFD)
- [ ] GPIO Driver
- [ ] ADC Driver
- [ ] ADC Validation
- [ ] Weight Calculation
- [ ] Software Calibration
- [ ] Digital Filtering
- [ ] Testing

---

## Future Enhancements

- ADC Interrupt Mode
- External Load Cell Integration
- High-Resolution External ADC Interface
- UART-Based Debug Logging

---

## License

This project is licensed under the MIT License.
