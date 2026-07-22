/*
 * stm32f407xx_adc.h
 *
 *  Created on: Jul 21, 2026
 *      Author: Manisha Daigavhane
 */

#ifndef STM32F407XX_ADC_H_
#define STM32F407XX_ADC_H_

//ADC_TypeDef
typedef struct
{
  volatile uint32_t SR;        // 0x00
  volatile uint32_t CR1;       // 0x04
  volatile uint32_t CR2;       // 0x08
  volatile uint32_t SMPR[2];   // 0x0C - 0x10
  volatile uint32_t JOFR[4];   // 0x14 - 0x20
  volatile uint32_t HTR;       // 0x24
  volatile uint32_t LTR;       // 0x28
  volatile uint32_t SQR[3];    // 0x2C - 0x34
  volatile uint32_t JSQR;      // 0x38
  volatile uint32_t JDR[4];    // 0x3C - 0x48
  volatile uint32_t DR;        // 0x4C
} ADC_TypeDef;

typedef struct
{
	volatile uint32_t CSR;     // 0x00
	volatile uint32_t CCR;     // 0x04
	volatile uint32_t CDR;     // 0x08
} ADC_Common_TypeDef;

//ADC Base Address
#define ADC1_BASE     0x40012000UL
#define ADC2_BASE     0x40012100UL
#define ADC3_BASE     0x40012200UL
#define ADC_COMMON_BASE     0x40012300UL

//Peripheral Pointers
#define ADC1 ((ADC_TypeDef *)ADC1_BASE)
#define ADC2 ((ADC_TypeDef *)ADC2_BASE)
#define ADC3 ((ADC_TypeDef *)ADC3_BASE)
#define ADC_COMMON ((ADC_Common_TypeDef *)ADC_COMMON_BASE)

//Bit definitions
#define ADC_CR2_ADON           (1U << 0)
#define ADC_CR2_CONT           (1U << 1)
#define ADC_CR2_SWSTART        (1U << 30)

#define ADC_SR_EOC             (1U << 1)
#define ADC_SR_OVR             (1U << 5)

#endif /* STM32F407XX_ADC_H_ */
