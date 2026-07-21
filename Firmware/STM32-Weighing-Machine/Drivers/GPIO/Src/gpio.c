/*
 * gpio.c
 *
 *  Created on: Jul 21, 2026
 *      Author: Manisha Daigavhane
 */

#include "gpio.h"

static void GPIO_EnableClock(GPIO_TypeDef *port){
	if(port == GPIOA)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	else if(port == GPIOB)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	else if(port == GPIOC)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	else if(port == GPIOD)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	else if(port == GPIOD)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	else if(port == GPIOE)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	else if(port == GPIOF)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	else if(port == GPIOG)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	else if(port == GPIOH)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	else if(port == GPIOI)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;
	else{
		/* Invalid GPIO port */
	}
}

static void GPIO_SetMode(GPIO_TypeDef *port,
                         uint8_t pin,
                         GPIO_Mode mode){

	port->MODER &= ~(3U << (pin * 2U));
	port->MODER |= (mode << (pin * 2U));
}

static void GPIO_SetPull(GPIO_TypeDef *port,
                         uint8_t pin,
                         GPIO_Pull pull){

	port->PUPDR &= ~(3U << (pin * 2U));
	port->PUPDR |= (pull << (pin * 2U));
}

static void GPIO_SetSpeed(GPIO_TypeDef *port,
                          uint8_t pin,
                          GPIO_Speed speed){
	port->OSPEEDR &= ~(3U << (pin * 2U));
	port->OSPEEDR |= (speed << (pin * 2U));

}

static void GPIO_SetOutputType(GPIO_TypeDef *port,
                               uint8_t pin,
                               GPIO_OutputType type){
	port->OTYPER &= ~(1U << pin);
	port->OTYPER |= (type << pin);

}

/**
 * @brief Configure a GPIO pin.
 *
 * @param port   GPIO port (GPIOA, GPIOB, ...)
 * @param pin    Pin number (0-15)
 * @param mode   Input, Output, AF or Analog
 * @param type   Push-Pull or Open-Drain
 * @param pull   Pull configuration
 * @param speed  Output speed
 */
void GPIO_ConfigPin(GPIO_TypeDef *port,
                    uint8_t pin,
                    GPIO_Mode mode,
                    GPIO_OutputType type,
                    GPIO_Pull pull,
                    GPIO_Speed speed){

	GPIO_EnableClock(port);

	GPIO_SetMode(port, pin, mode);

	GPIO_SetOutputType(port, pin, type);

	GPIO_SetPull(port, pin, pull);

	GPIO_SetSpeed(port, pin, speed);

}

void GPIO_SetAlternateFunction(GPIO_TypeDef *port,
                                      uint8_t pin,
                                      uint8_t alternateFunction)
{
    if(pin < 8U)
    {
        /* AFRL : Pins 0-7 */
        port->AFR[0] &= ~(0xFU << (pin * 4U));
        port->AFR[0] |= ((uint32_t)alternateFunction << (pin * 4U));
    }
    else
    {
        /* AFRH : Pins 8-15 */
        uint8_t position = pin - 8U;

        port->AFR[1] &= ~(0xFU << (position * 4U));
        port->AFR[1] |= ((uint32_t)alternateFunction << (position * 4U));
    }
}

void GPIO_SetPin(GPIO_TypeDef *port, uint8_t pin)
{
	port->BSRR = (1<<pin);
}

void GPIO_ClearPin(GPIO_TypeDef *port, uint8_t pin)
{
	port->BSRR = (1<<(pin+16)); //BSRR -> 0-15 bits are set bits, 16-31 are reset bits
}

void GPIO_TogglePin(GPIO_TypeDef *port, uint8_t pin)
{
	port->ODR ^= (1<<pin);
}


