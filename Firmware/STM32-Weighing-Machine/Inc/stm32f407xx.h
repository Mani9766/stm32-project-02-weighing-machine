/*
 * stm32f407xx.h
 *
 *  Created on: Jul 21, 2026
 *      Author: Manisha Daigavhane
 */

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#include <stdint.h>

//GPIO_TypeDef
typedef struct
{
  volatile uint32_t MODER;        // 0x00
  volatile uint32_t OTYPER;       // 0x04
  volatile uint32_t OSPEEDR;      // 0x08
  volatile uint32_t PUPDR;        // 0x0C
  volatile uint32_t IDR;          // 0x10
  volatile uint32_t ODR;          // 0x14
  volatile uint32_t BSRR;         // 0x18
  volatile uint32_t LCKR;         // 0x1C
  volatile uint32_t AFR[2];       // 0x20, 0x24
} GPIO_TypeDef;

//RCC_TypeDef
typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
           uint32_t RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
           uint32_t RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
           uint32_t RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
           uint32_t RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
           uint32_t RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
           uint32_t RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
           uint32_t RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
} RCC_TypeDef;

//ADC_TypeDef
//
//Base Addresses
//GPIO Base Addresses
#define GPIOA_BASE    0x40020000UL
#define GPIOB_BASE    0x40020400UL
#define GPIOC_BASE    0x40020800UL
#define GPIOD_BASE    0x40020C00UL
#define GPIOE_BASE    0x40021000UL
#define GPIOF_BASE    0x40021400UL
#define GPIOG_BASE    0x40021800UL
#define GPIOH_BASE    0x40021C00UL
#define GPIOI_BASE    0x40022000UL

#define RCC_BASE      0x40023800UL

//Peripheral Pointers
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)
#define GPIOI ((GPIO_TypeDef *)GPIOI_BASE)

#define RCC   ((RCC_TypeDef *)RCC_BASE)

//Bit definitions
#define RCC_AHB1ENR_GPIOAEN      (1U << 0)
#define RCC_AHB1ENR_GPIOBEN      (1U << 1)
#define RCC_AHB1ENR_GPIOCEN      (1U << 2)
#define RCC_AHB1ENR_GPIODEN      (1U << 3)
#define RCC_AHB1ENR_GPIOEEN      (1U << 4)
#define RCC_AHB1ENR_GPIOFEN      (1U << 5)
#define RCC_AHB1ENR_GPIOGEN      (1U << 6)
#define RCC_AHB1ENR_GPIOHEN      (1U << 7)
#define RCC_AHB1ENR_GPIOIEN      (1U << 8)



#endif /* STM32F407XX_H_ */
