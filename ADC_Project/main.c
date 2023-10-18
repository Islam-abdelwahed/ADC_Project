#define F_CPU 16000000
#include <util/delay.h>
#include "LCD.h"
#include "ADC.h"
#include "KEYPAD.h"
#include "Buzzer.h"
#include "Relay.h"
void Write_Temp()
{
	ADC_SelectChannel(ADC_CHANNEL_1);
	uint8_t x = 1;
	uint16_t Temperature = 0;
	while (x) {
	
		ADC_Read(&Temperature);
		Temperature=(Temperature*500)/1024;
		LCD_WRITE_STRING("Temp=");
		LCD_WRITE_INTEGER(Temperature);
		LCD_WRITE_CHAR(223); // Write ° Symbol
		LCD_WRITE_CHAR('C');
		LOCATE_CURSOR(3, 0);
		LCD_WRITE_STRING("Hold any key to back");
		uint8_t val = keypadGetValue();
		if (val) {
			BUZZER_SHORT_BEEP();
			x = 0;
		}
		_delay_ms(1000);
		LCD_CLR();
	}
	main();
}

void Write_LDR()
{
	ADC_SelectChannel(ADC_CHANNEL_0);
	uint8_t x = 1;
	uint16_t LDR = 0;
	while (x) {
		
		ADC_Read(&LDR);
		
		LCD_WRITE_STRING("LDR=");
		
		if (LDR > 50) {
			Relay_ON(1);
			LCD_WRITE_STRING("Dark");
		}
		else if (LDR <= 50) {
			Relay_OFF(1);
			LCD_WRITE_STRING("Light");
		}
		LOCATE_CURSOR(3, 0);
		LCD_WRITE_STRING("Hold any key to back");
		uint8_t val = keypadGetValue();
		if (val) {
			BUZZER_SHORT_BEEP();
			x = 0;
		}
		_delay_ms(1000);
		LCD_CLR();
	}
	main();
}

int main(void)
{
	ADC_Init();
	LCD_INIT();
	Relay_Init(1);
	KEYPAD_INIT();
	BUZZER_Init();
	LCD_WRITE_STRING("1.Temperature Sensor");
	LOCATE_CURSOR(2, 0);
	LCD_WRITE_STRING("2.LDR Sensor");
	while (1)
	{
		uint8_t val = keypadGetValue();
		if (val)
		{
			BUZZER_SHORT_BEEP();
			if (val == '1')
			{
				LCD_CLR();
				Write_Temp();
			}
			else if (val == '2')
			{
				LCD_CLR();
				Write_LDR();
			}
		}
	}
}