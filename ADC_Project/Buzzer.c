
#include "Buzzer.h"

void BUZZER_Init(void){
	DIO_setPinDir(BUZZER_PORT, BUZZER_PIN, DIO_PIN_OUTPUT);
	DIO_setPinValue(BUZZER_PORT, BUZZER_PIN, DIO_PIN_LOW);
	};
	
void BUZZER_Status(uint8 Buz_sta){
	if (Buz_sta)
	{
		DIO_setPinValue(BUZZER_PORT, BUZZER_PIN, DIO_PIN_HIGH);
	}else{
		DIO_setPinValue(BUZZER_PORT, BUZZER_PIN, DIO_PIN_LOW);
	}
	};
	
void BUZZER_Toggle(void){
	DIO_togglePin(BUZZER_PORT, BUZZER_PIN);
	};
	
void BUZZER_SHORT_BEEP(void){
	BUZZER_Status(BUZZER_ON);
	_delay_ms(100);
	BUZZER_Status(BUZZER_OFF);
	};
	
void BUZZER_LONG_BEEP(void){
	BUZZER_Status(BUZZER_ON);
	_delay_ms(1000);
	BUZZER_Status(BUZZER_OFF);
}
void BUZZER_BEEP_BEEP(void){
	BUZZER_Status(BUZZER_ON);
	_delay_ms(70);
	BUZZER_Status(BUZZER_OFF);
	_delay_ms(35);
	BUZZER_Status(BUZZER_ON);
	_delay_ms(70);
	BUZZER_Status(BUZZER_OFF);
}