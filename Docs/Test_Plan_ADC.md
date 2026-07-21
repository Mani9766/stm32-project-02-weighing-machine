# ADC Test Plan

**Project Name:** STM32 Project 02 – ADC-Based Weighing Machine

**Module:** ADC Driver

**Version:** 1.0

---

# 1. Purpose

This document defines the test strategy for verifying the ADC driver.

The objective is to ensure that the ADC driver functions correctly under normal operating conditions and handles error conditions appropriately.

---

# 2. Test Environment

| Item | Description |
|------|-------------|
| MCU | STM32F407VG |
| Development Board | STM32F407 Discovery |
| IDE | STM32CubeIDE |
| Debugger | ST-Link |
| Programming Language | C |
| ADC Mode | Polling |
| Resolution | 12-bit |

---

# 3. Test Strategy

The ADC driver will be tested incrementally.

1. Peripheral Initialization
2. GPIO Configuration
3. ADC Conversion
4. ADC Result Validation
5. Voltage Calculation
6. Weight Calculation
7. Error Handling

---

# 4. Test Cases

## TC-001 : ADC Clock Enable

### Objective

Verify that the ADC peripheral clock is enabled.

### Procedure

- Initialize ADC.
- Inspect RCC APB2 peripheral enable register.

### Expected Result

ADC1 clock enable bit is set.

---

## TC-002 : GPIO Analog Configuration

### Objective

Verify that the selected GPIO pin is configured in Analog Mode.

### Procedure

- Initialize GPIO.
- Inspect GPIO MODER register.

### Expected Result

GPIO pin is configured as Analog.

---

## TC-003 : ADC Initialization

### Objective

Verify successful ADC initialization.

### Procedure

- Call ADC_Init().

### Expected Result

ADC is enabled successfully.

---

## TC-004 : Start ADC Conversion

### Objective

Verify that software can trigger ADC conversion.

### Procedure

- Call ADC_StartConversion().

### Expected Result

ADC conversion begins.

---

## TC-005 : Read ADC Value

### Objective

Verify ADC conversion result.

### Procedure

- Start conversion.
- Wait for End Of Conversion.
- Read ADC_DR.

### Expected Result

ADC value is between 0 and 4095.

---

## TC-006 : Voltage Conversion

### Objective

Verify ADC count to voltage conversion.

### Procedure

- Read ADC value.
- Convert using reference voltage.

### Expected Result

Calculated voltage matches expected input.

---

## TC-007 : Weight Calculation

### Objective

Verify voltage-to-weight conversion.

### Procedure

- Apply calibration equation.

### Expected Result

Calculated weight matches expected value.

---

## TC-008 : Continuous Operation

### Objective

Verify continuous ADC operation.

### Procedure

- Perform repeated conversions.

### Expected Result

ADC continues operating without errors.

---

# 5. Pass Criteria

The ADC driver shall pass all test cases without:

- Incorrect ADC values
- Driver failures
- Peripheral lock-up
- Unexpected behaviour

---

# 6. Future Test Cases

The following tests will be added in future versions:

- Continuous Conversion
- Scan Mode
- Interrupt Mode
- Overrun Detection
- Multi-channel Conversion
- Performance Measurement

---
