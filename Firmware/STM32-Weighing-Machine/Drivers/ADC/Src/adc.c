/*
 * adc.c
 *
 *  Created on: Jul 21, 2026
 *      Author: Manisha Daigavhane
 */

#include "adc.h"

static void ADC_EnableClock(ADC_TypeDef *adc)
{
    if(adc == ADC1)
    {
        RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    }
    else if(adc == ADC2)
    {
        RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
    }
    else if(adc == ADC3)
    {
        RCC->APB2ENR |= RCC_APB2ENR_ADC3EN;
    }
}

static void ADC_SetPrescaler(ADC_Prescalar prescalar)
{
    ADC_COMMON->CCR &= ~(3U << 16U);;
    ADC_COMMON->CCR |= ((uint32_t)prescalar << 16U);
}

static void ADC_SetResolution(ADC_TypeDef *adc, ADC_Resolution res){
	adc->CR1 &= ~(3U << 24U);
	adc->CR1 |= ((uint32_t)res << 24U);
}

static void ADC_SetAlignment(ADC_TypeDef *adc, Data_Alignment align){
	/* Right alignment (default) */
	adc->CR2 &= ~(1U << 11U);
	adc->CR2 |= ((uint32_t)align << 11U);
}
static void ADC_SetScanMode(ADC_TypeDef *adc, Scan_Mode scan){
    /* Enable/Disable scan mode */
    adc->CR1 &= ~(1U << 8U);
    adc->CR1 |= ((uint32_t)scan << 8U);
}
static void ADC_SetContinuousMode(ADC_TypeDef *adc, Conversion_Mode conv_mode){
    /* Single conversion mode */
	adc->CR2 &= ~(1U << 1U);
	adc->CR2 |= ((uint32_t)conv_mode << 1U);
}
static void ADC_SetState(ADC_TypeDef *adc, ADC_State ADON){
	if(ADON == ADC_En)
	{
	    adc->CR2 |= ADC_CR2_ADON;
	}
	else
	{
	    adc->CR2 &= ~ADC_CR2_ADON;
	}
}

void ADC_Init(ADC_TypeDef *adc,
		ADC_Prescalar prescalar,
		ADC_Resolution res,
		Data_Alignment align,
		Scan_Mode scan,
		Conversion_Mode conv_mode,
		ADC_State ADON){

	assert(adc == ADC1 || adc == ADC2 || adc == ADC3);

	ADC_EnableClock(adc);

    ADC_SetPrescaler(prescalar);

    ADC_SetResolution(adc, res);

    ADC_SetAlignment(adc, align);

    ADC_SetScanMode(adc, scan);

    ADC_SetContinuousMode(adc, conv_mode);

    ADC_SetState(adc, ADON);

}

static void ADC_SetSamplingTime(ADC_TypeDef *adc, uint8_t channel, Sampling_Time sample_time){

	adc->SMPR[1U - channel/10U] &= ~(7U << ((channel % 10U) * 3U));
	adc->SMPR[1U - channel/10U] |= ((uint32_t)sample_time << ((channel % 10U) * 3U));

	assert(channel <= 18U);

}

static void ADC_SetConversionSequenceNumber(ADC_TypeDef *adc, uint8_t channel, Conv_Seq_No rank){

	adc->SQR[2U - (rank - 1U)/6U] &= ~(0x1FU << (((rank - 1U) % 6U) * 5U));
	adc->SQR[2U - (rank - 1U)/6U] |= ((uint32_t)channel << (((rank - 1U) % 6U) * 5U));

	assert(rank >= conv_seq_1 && rank <= conv_seq_16);
}

static void ADC_SetSequenceLength(ADC_TypeDef *adc, uint8_t No_Of_Channels){
	 adc->SQR[0U] &= ~(0xFU << 20U);
	 adc->SQR[0U] |= ((No_Of_Channels - 1U) << 20U);
}


void ADC_ConfigChannel(ADC_TypeDef *adc, uint8_t channel, Sampling_Time sample_time, Conv_Seq_No rank, uint8_t No_Of_Channels){

	ADC_SetSamplingTime(adc, channel, sample_time);

	ADC_SetConversionSequenceNumber(adc, channel, rank);

	ADC_SetSequenceLength(adc, No_Of_Channels);
}

void ADC_StartConversion(ADC_TypeDef *adc){
	adc->CR2 |= ADC_CR2_SWSTART;
}

uint16_t ADC_ReadData(ADC_TypeDef *adc){
	return adc->DR;
}

static void ADC_WaitForConversion(ADC_TypeDef *adc)
{
    while(!(adc->SR & ADC_SR_EOC));
}

uint16_t ADC_ReadChannelSingleCoversion(ADC_TypeDef *adc, uint8_t channel, Sampling_Time sample_time){
	ADC_ConfigChannel(adc,
	                      channel,
	                      sample_time,
	                      conv_seq_1,
	                      1U);

	ADC_StartConversion(adc);

	ADC_WaitForConversion(adc);

	return ADC_ReadData(adc);
}
