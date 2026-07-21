# ADC Design Decisions

**Project Name:** STM32 Project 02 – ADC-Based Weighing Machine

**Module:** ADC Driver

**Version:** 1.0

---

# 1. Purpose

This document records the architectural and implementation decisions made during the development of the ADC-Based Weighing Machine project.

The objective is to explain why specific design choices were made and to maintain consistency throughout the project.

---

# DD-001 : Why Bare-Metal Programming?

## Decision

Use CMSIS register-level programming instead of HAL peripheral APIs.

## Reason

- Better understanding of STM32 peripherals
- Complete control over hardware configuration
- Improved debugging during firmware development
- Stronger firmware fundamentals

---

# DD-002 : Why Layered Architecture?

## Decision

Divide the firmware into Application, Service and Driver layers.

## Reason

- Separation of concerns
- Easier maintenance
- Improved scalability
- Better software organization

---

# DD-003 : Why a Separate ADC Driver?

## Decision

Create a dedicated ADC driver.

## Reason

- Hardware abstraction
- Driver reusability
- Simplified application logic
- Easier future maintenance

---

# DD-004 : Why Polling Mode?

## Decision

Implement polling mode in Version 1.

## Reason

- Simpler implementation
- Easier debugging
- Ideal for learning peripheral behavior
- Forms the foundation for interrupt and DMA modes

---

# DD-005 : Why 12-bit Resolution?

## Decision

Use the maximum ADC resolution supported by STM32F407.

## Reason

- Higher measurement precision
- Smaller voltage step size
- Better weight measurement accuracy

---

# DD-006 : Why Right Data Alignment?

## Decision

Store ADC data using right alignment.

## Reason

- Direct integer access
- Simpler calculations
- No additional bit shifting required

---

# DD-007 : Why Modular Drivers?

## Decision

Keep GPIO and ADC as independent modules.

## Reason

- Independent testing
- Improved code reuse
- Lower coupling between modules

---

# DD-008 : Why Service Layer?

## Decision

Perform weight calculation inside the service layer instead of the driver.

## Reason

- Drivers should only access hardware
- Business logic remains hardware-independent
- Future hardware changes affect only the driver layer

---

# DD-009 : Why Internal Temperature Sensor?

## Decision

Use the internal temperature sensor only for initial ADC validation.

## Reason

- No additional hardware required
- Quick verification of ADC functionality
- Easy transition to an external analog sensor later

---

# DD-010 : Why Documentation Before Coding?

## Decision

Complete project documentation before implementation.

## Reason

- Clear understanding of requirements
- Better software planning
- Reduced implementation errors
- Easier project maintenance

---

# Future Design Decisions

Additional decisions will be documented as the project evolves.

Examples:

- Interrupt Mode
- DMA Integration
- Digital Filtering
- Calibration Strategy
- Error Handling
