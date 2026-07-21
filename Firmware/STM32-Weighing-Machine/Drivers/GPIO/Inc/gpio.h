/*
 * gpio.h
 *
 *  Created on: Jul 21, 2026
 *      Author: Manisha Daigavhane
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "common.h"

typedef enum
{
    GPIO_INPUT = 0,
    GPIO_OUTPUT,
    GPIO_AF,
    GPIO_ANALOG

} GPIO_Mode;

typedef enum
{
    GPIO_PUSH_PULL = 0,
    GPIO_OPEN_DRAIN

} GPIO_OutputType;

typedef enum
{
    GPIO_NO_PULL = 0,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN

} GPIO_Pull;

typedef enum
{
    GPIO_LOW_SPEED = 0,
    GPIO_MEDIUM_SPEED,
    GPIO_FAST_SPEED,
    GPIO_HIGH_SPEED

} GPIO_Speed;

void GPIO_ConfigPin(GPIO_TypeDef *port,
                    uint8_t pin,
                    GPIO_Mode mode,
                    GPIO_OutputType type,
                    GPIO_Pull pull,
                    GPIO_Speed speed);

void GPIO_SetAlternateFunction(GPIO_TypeDef *port,
                               uint8_t pin,
                               uint8_t alternateFunction);

void GPIO_SetPin(GPIO_TypeDef *port, uint8_t pin);

void GPIO_ClearPin(GPIO_TypeDef *port, uint8_t pin);

void GPIO_TogglePin(GPIO_TypeDef *port, uint8_t pin);

#endif /* GPIO_H_ */
