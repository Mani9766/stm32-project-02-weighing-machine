# Low-Level Design (LLD)

## Module Name

ADC Driver

---

## 1. Purpose

The ADC Driver provides a hardware abstraction for the STM32F407 ADC peripheral.

The driver is responsible for:

- ADC initialization
- Channel configuration
- Starting conversion
- Reading conversion results
- Stopping conversion

The application layer shall never access ADC registers directly.

---

# 2. Module Architecture

```text
Application

↓

WeighingMachine_Service()

↓

ADC Driver API

↓

CMSIS Registers

↓

STM32 ADC Hardware
```

---

# 3. Public APIs

## ADC_Init()

### Description

Initializes the ADC peripheral.

### Prototype

```c
void ADC_Init(void);
```

---

## ADC_StartConversion()

### Description

Starts ADC conversion.

### Prototype

```c
void ADC_StartConversion(void);
```

---

## ADC_Read()

### Description

Reads converted ADC value.

### Prototype

```c
uint16_t ADC_Read(void);
```

---

## ADC_Stop()

### Description

Stops ADC conversion.

### Prototype

```c
void ADC_Stop(void);
```

---

# 4. Internal Functions

Initially none.

Private helper functions may be added if required.

---

# 5. Register Usage

| Register | Purpose |
|----------|---------|
| RCC->APB2ENR | Enable ADC clock |
| GPIOx_MODER | Configure Analog Pin |
| ADC_CR1 | ADC configuration |
| ADC_CR2 | Enable ADC |
| ADC_SMPRx | Sampling Time |
| ADC_SQR1 | Sequence Length |
| ADC_SQR2 | Sequence Configuration |
| ADC_SQR3 | Channel Selection |
| ADC_SR | Status Flags |
| ADC_DR | Conversion Result |

---

# 6. Driver Flow

```text
ADC_Init()

↓

Enable ADC Clock

↓

Configure GPIO

↓

Configure Sample Time

↓

Configure Sequence

↓

Enable ADC

↓

Ready
```

---

# 7. Conversion Flow

```text
ADC_StartConversion()

↓

Set SWSTART

↓

Wait for EOC

↓

Read ADC_DR

↓

Return Value
```

---

# 8. Dependencies

The ADC Driver depends on:

- RCC
- GPIO Driver
- CMSIS Register Definitions

---

# 9. Error Handling

The driver shall detect:

- ADC Overrun
- Timeout
- Invalid Channel Configuration

---

# 10. Assumptions

- Single ADC
- Single Channel
- Polling Mode
- 12-bit Resolution
- Right Alignment

---

# 11. Future Enhancements

- Scan Conversion
- Continuous Conversion
- Interrupt Mode
- DMA Support
- Multi-channel Sampling

---
