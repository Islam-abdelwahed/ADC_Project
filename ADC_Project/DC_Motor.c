#include "DC_Motor.h"


void DCMotor_Init(void){
	DIO_setPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	
	PWM0_Init();
}


void DCMotor_SetDir(DC_MOTOTR_DIR Dir){
	switch(Dir){
		case CLOCK_WISE_DIR:
		DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
		break;
		
		case ANTI_CLOCK_WISE_DIR:
		DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
		break;
	}
	
}

void DCMotor_SetSpeed(uint8 speed){
	speed *=10;
	PWM_Generate(speed);
}

void DCMotr_Start(void) {
	PWM_Start();
}

void DCMotr_Stop(void){
	DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
}

