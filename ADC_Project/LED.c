
#include "LED.h"

void LED_Init(LED_COLOR Color){
	switch(Color)
	{
		case RED_LED:
		DIO_setPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);
		break;
		case GREEN_LED:
		DIO_setPinDir(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
		break;
		case BLUE_LED:
		DIO_setPinDir(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
		break;
		case YELLOW_LED:
		DIO_setPinDir(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
		break;

	}
	
}
void LED_ON(LED_COLOR Color){
	switch(Color)
	{
		case RED_LED:
		DIO_setPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
		break;
		case GREEN_LED:
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		break;
		case BLUE_LED:
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		break;
		case YELLOW_LED:
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
		break;
	
	}
}
void LED_OFF(LED_COLOR Color){
	switch(Color)
	{
		case RED_LED:
		DIO_setPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
		break;
		case GREEN_LED:
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		break;
		case BLUE_LED:
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		break;
		case YELLOW_LED:
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
		break;
	}
}
void LED_Toggle(LED_COLOR Color){
	switch(Color)
	{
		case RED_LED:
		DIO_togglePin(DIO_PORTB,DIO_PIN7);
		break;
		case GREEN_LED:
		DIO_togglePin(DIO_PORTA,DIO_PIN4);
		break;
		case BLUE_LED:
		DIO_togglePin(DIO_PORTA,DIO_PIN5);
		break;
		case YELLOW_LED:
		DIO_togglePin(DIO_PORTA,DIO_PIN6);
		break;
	}
}