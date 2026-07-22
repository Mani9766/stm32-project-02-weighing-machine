/*
 * stm32f407xx_gpio.h
 *
 *  Created on: Jul 21, 2026
 *      Author: Manisha Daigavhane
 */

#ifndef STM32F407XX_GPIO_H_
#define STM32F407XX_GPIO_H_

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

#endif /* STM32F407XX_GPIO_H_ */
