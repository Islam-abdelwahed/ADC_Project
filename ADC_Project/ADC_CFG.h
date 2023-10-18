/*
 * ADC_Config.h
 *
 * Created: 2023/8/7 5:33:57 PM
 *  Author: Ahmed Adel
 */ 
// LM35 Is On Channel 1
// LDR	Is On Channel 0

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_VOLTAGE_REFERENCE		ADC_VREF_AVCC

#define ADC_ADJUST					ADC_RIGHT_ADJUST

#define ADC_CHANNEL					ADC_CHANNEL_0 

#define ADC_CONVERSION_TRIGGER		ADC_AUTO_TRIGGER

#define ADC_PRESCALER				ADC_PRESC_128

#define ADC_INTERRUPT_STATE			ADC_INTERRUPT_DISABLE

#endif /* ADC_CONFIG_H_ */