# Data Flow Diagram (DFD)

**Project Name:** STM32 Project 02 – ADC-Based Weighing Machine

**Version:** 1.0

---

# 1. Purpose

This document describes the flow of data through the firmware.

Unlike the System Block Diagram, which focuses on hardware components, the Data Flow Diagram illustrates how information is processed by the software.

---

# 2. Data Flow Diagram

```text
               Analog Voltage
                      │
                      ▼
             +----------------+
             |  ADC Hardware  |
             +----------------+
                      │
               ADC Conversion
                      │
                      ▼
             +----------------+
             |    ADC Driver  |
             +----------------+
                      │
                ADC Count
                      │
                      ▼
             +----------------+
             | Voltage Module |
             +----------------+
                      │
                 Voltage (V)
                      │
                      ▼
             +----------------+
             | Calibration    |
             +----------------+
                      │
              Calibrated Value
                      │
                      ▼
             +----------------+
             | Weight Module  |
             +----------------+
                      │
               Weight (kg)
                      │
                      ▼
             +----------------+
             | Application    |
             +----------------+
```

---

# 3. Data Processing Stages

## Stage 1 – Analog Signal Acquisition

The analog input voltage is sampled by ADC1.

Output:

- Analog Voltage

---

## Stage 2 – ADC Conversion

ADC converts the sampled voltage into a 12-bit digital value.

Output:

- ADC Count (0–4095)

---

## Stage 3 – Voltage Conversion

The ADC count is converted into the corresponding input voltage.

Output:

- Voltage (Volts)

---

## Stage 4 – Calibration

Calibration is applied to compensate for sensor offset and scaling.

Output:

- Calibrated Voltage

---

## Stage 5 – Weight Calculation

The calibrated value is converted into weight.

Output:

- Weight (kg)

---

## Stage 6 – Application

The calculated weight is made available to the application layer for further processing.

---

# 4. Input and Output Summary

| Stage | Input | Output |
|--------|-------|--------|
| ADC Hardware | Analog Voltage | ADC Count |
| ADC Driver | ADC Count | Digital Data |
| Voltage Module | ADC Count | Voltage |
| Calibration | Voltage | Calibrated Voltage |
| Weight Module | Calibrated Voltage | Weight |
| Application | Weight | Processed Result |

---

# 5. Future Enhancements

The data flow can be extended to include:

- Digital filtering
- Moving average
- UART transmission
- Display interface
- Data logging

---
