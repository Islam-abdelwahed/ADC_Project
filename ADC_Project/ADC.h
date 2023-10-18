/*
 * ADC.h
 *
 * Created: 2023/8/7 5:33:33 PM
 *  Author: Ahmed Adel
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Atmega32_Registers.h"
#include "BIT_MATH.h"
#include "ADC_CFG.h"

#define ADC_VREF_AVCC			0

#define ADC_VREF_INTERNAL		1 // 2.56V

//================[CHANNELS]==============//

#define ADC_CHANNEL_0			0

#define ADC_CHANNEL_1			1

#define ADC_CHANNEL_2			2

#define ADC_CHANNEL_3			3

#define ADC_CHANNEL_4			4

#define ADC_CHANNEL_5			5

#define ADC_CHANNEL_6			6

#define ADC_CHANNEL_7			7

//========================================//

#define ADC_AUTO_TRIGGER		0

//================[ADJUST]=================//

#define ADC_RIGHT_ADJUST		0

#define ADC_LEFT_ADJUST			1

//=========================================//

#define ADC_PRESC_128			0

//================[INTERRUPT]==============//

#define ADC_INTERRUPT_ENABLE	0

#define ADC_INTERRUPT_DISABLE	1

//=========================================//

void ADC_Init(void);

void ADC_SelectChannel(uint8 Channel);

void ADC_Read(uint16* Value);

#endif /* ADC_H_ */