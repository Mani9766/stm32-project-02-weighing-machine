# Firmware API Design

**Project Name:** STM32 Project 02 – ADC-Based Weighing Machine

**Version:** 1.0

---

# 1. Purpose

This document defines the public firmware interfaces used by the application.

The objective is to establish a stable API before implementation begins.

---

# 2. Software Modules

The firmware is divided into the following modules:

- GPIO Driver
- ADC Driver
- Weighing Machine Service

---

# 3. GPIO Driver APIs

## GPIO_Init()

```c
void GPIO_Init(void);
```

### Description

Initializes GPIO pins required by the application.

---

# 4. ADC Driver APIs

## ADC_Init()

```c
void ADC_Init(void);
```

### Description

Initializes the ADC peripheral.

---

## ADC_StartConversion()

```c
void ADC_StartConversion(void);
```

### Description

Starts ADC conversion.

---

## ADC_Read()

```c
uint16_t ADC_Read(void);
```

### Description

Reads the converted ADC value.

---

## ADC_Stop()

```c
void ADC_Stop(void);
```

### Description

Stops ADC conversion.

---

# 5. Weighing Machine Service APIs

## WeighingMachine_Init()

```c
void WeighingMachine_Init(void);
```

### Description

Initializes the weighing machine service.

---

## WeighingMachine_Task()

```c
void WeighingMachine_Task(void);
```

### Description

Executes one iteration of the weighing machine application.

Responsibilities:

- Read ADC value
- Convert ADC count to voltage
- Apply calibration
- Calculate weight
- Return processed result

---

# 6. Firmware Call Flow

```text
main()

↓

GPIO_Init()

↓

ADC_Init()

↓

WeighingMachine_Init()

↓

while(1)
{
    WeighingMachine_Task();
}
```

---

# 7. API Design Guidelines

- APIs shall have a single responsibility.
- Hardware access shall remain inside driver modules.
- Application code shall not access peripheral registers directly.
- Drivers shall expose only required public interfaces.
- Future enhancements should not require changes to the application layer.

---

# 8. Future APIs

Future versions may introduce:

```c
void ADC_EnableInterrupt(void);

void ADC_DisableInterrupt(void);

void ADC_SetChannel(uint8_t channel);

void ADC_SetSamplingTime(...);

void ADC_EnableDMA(void);

void ADC_DisableDMA(void);
```

These APIs are intentionally excluded from Version 1 to keep the initial implementation focused and easy to validate.

---
