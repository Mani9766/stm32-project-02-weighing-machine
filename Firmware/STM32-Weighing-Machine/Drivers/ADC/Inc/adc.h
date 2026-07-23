/*
 * adc.h
 *
 *  Created on: Jul 21, 2026
 *      Author: Manisha Daigavhane
 */

#ifndef ADC_INC_ADC_H_
#define ADC_INC_ADC_H_

#include "common.h"

typedef enum{
	ADC_CLOCK_DIV2 = 0,
	ADC_CLOCK_DIV4,
	ADC_CLOCK_DIV6,
	ADC_CLOCK_DIV8
} ADC_Prescalar;

typedef enum{
	Bit_Resolution_12 = 0,
	Bit_Resolution_10,
	Bit_Resolution_8,
	Bit_Resolution_6
} ADC_Resolution;

typedef enum{
	Scan_disable = 0,
	scan_enable,
} Scan_Mode;

typedef enum{
	Right_Alignment = 0,
	Left_Alignment,
} Data_Alignment;

typedef enum{
	single_Conversion = 0,
	Cont_Conversion,
} Conversion_Mode;

typedef enum{
	ADC_Dis = 0,
	ADC_En
} ADC_State;

typedef enum{
	Cycles_3 = 0,
	Cycles_15,
	Cycles_28,
	Cycles_56,
	Cycles_82,
	Cycles_112,
	Cycles_144,
	Cycles_480
} Sampling_Time;

typedef enum{
	conv_seq_1 = 1,
	conv_seq_2,
	conv_seq_3,
	conv_seq_4,
	conv_seq_5,
	conv_seq_6,
	conv_seq_7,
	conv_seq_8,
	conv_seq_9,
	conv_seq_10,
	conv_seq_11,
	conv_seq_12,
	conv_seq_13,
	conv_seq_14,
	conv_seq_15,
	conv_seq_16,
} Conv_Seq_No;

void ADC_Init(ADC_TypeDef *adc, ADC_Prescalar prescalar, ADC_Resolution res, Data_Alignment align,
		Scan_Mode scan, Conversion_Mode conv_mode, ADC_State ADON);

void ADC_ConfigChannel(ADC_TypeDef *adc, uint8_t channel, Sampling_Time sample_time, Conv_Seq_No rank, uint8_t No_Of_Channels);

void ADC_StartConversion(ADC_TypeDef *adc);

uint16_t ADC_ReadData(ADC_TypeDef *adc);

void ADC_WaitForConversion(ADC_TypeDef *adc);

uint16_t ADC_ReadChannelSingleConversion(ADC_TypeDef *adc, uint8_t channel, Sampling_Time sample_time);

#endif /* ADC_INC_ADC_H_ */
