/*
 * ADC.c
 *
 * Created: 2023/8/7 5:34:14 PM
 *  Author: Ahmed Adel
 */ 

#include "ADC.h"



void ADC_Init(void)
{
	#if ADC_VOLTAGE_REFERENCE	==	ADC_VREF_AVCC
	
	CLR_BIT(ADMUX , 7);
	SET_BIT(ADMUX , 6);
	
	#elif ADC_VOLTAGE_REFERENCE	==	ADC_VREF_INTERNAL
	
	SET_BIT(ADMUX , 7);
	SET_BIT(ADMUX , 6);
	
	#endif

	#if ADC_ADJUST				==	ADC_RIGHT_ADJUST
	
	CLR_BIT(ADMUX , 5);
	
	#elif ADC_ADJUST			== ADC_LEFT_ADJUST
	
	SET_BIT(ADMUX , 5);
	
	#endif

	#if ADC_CHANNEL				==	ADC_CHANNEL_1
	
	SET_BIT(ADMUX , 0);
	
	#elif ADC_CHANNEL			==	ADC_CHANNEL_2
	
	SET_BIT(ADMUX , 1);
	
	#elif ADC_CHANNEL			==	ADC_CHANNEL_3
	
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	
	#elif ADC_CHANNEL			==	ADC_CHANNEL_4
	
	SET_BIT(ADMUX , 3);
	
	#elif ADC_CHANNEL			==	ADC_CHANNEL_5
	
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 3);
	
	#elif ADC_CHANNEL			==	ADC_CHANNEL_6
	
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	
	#elif ADC_CHANNEL			==	ADC_CHANNEL_7
	
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	
	#endif

	#if ADC_CONVERSION_TRIGGER	==	ADC_AUTO_TRIGGER
	
	SET_BIT(ADCSRA , 5);
	
	#endif

	#if ADC_PRESCALER			==	ADC_PRESC_128
	
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	
	#endif

	#if ADC_INTERRUPT_STATE		==	ADC_INTERRUPT_DISABLE
	
	CLR_BIT(ADCSRA , 3);
	
	#elif ADC_INTERRUPT_STATE		==	ADC_INTERRUPT_ENABLE
	
	SET_BIT(ADCSRA , 3);
	//SET_BIT(SREG, 1);
	
	#endif
	
	//==> ADC Enable
	SET_BIT(ADCSRA , 7);
}

void ADC_SelectChannel(uint8 Channel)
{
	ADMUX&=0xE0;
	
	switch(Channel)
	{
		case ADC_CHANNEL_0:
		CLR_BIT(ADMUX , 0);
		CLR_BIT(ADMUX , 1);
		CLR_BIT(ADMUX , 2);
		
		break;
		case ADC_CHANNEL_1:
			SET_BIT(ADMUX , 0);
			break;
		case ADC_CHANNEL_2:
			SET_BIT(ADMUX , 1);
			break;
		case ADC_CHANNEL_3:
			SET_BIT(ADMUX , 0);
			SET_BIT(ADMUX , 1);
			break;
		case ADC_CHANNEL_4:
			SET_BIT(ADMUX , 2);
			break;
		case ADC_CHANNEL_5:
			SET_BIT(ADMUX , 0);
			SET_BIT(ADMUX , 2);
			break;
		case ADC_CHANNEL_6:
			SET_BIT(ADMUX , 1);
			SET_BIT(ADMUX , 2);
			break;
		case ADC_CHANNEL_7:
			SET_BIT(ADMUX , 0);
			SET_BIT(ADMUX , 1);
			SET_BIT(ADMUX , 2);
			break;
		default:
			break;
	}
}
void ADC_Read(uint16* Value)
{
	uint16 Digital_Value = 0;
	//Start Conversion
	SET_BIT(ADCSRA , 6);
			
	while(!GET_BIT(ADCSRA,4));
	
	*Value = ADC_VALUE;

	
}