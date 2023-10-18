
#include "Relay.h"

/*---------------Relay--------------*/
void Relay_Init(uint8 Relay)
{
	#if Relay==Relay1
	DIO_setPinDir(Relay1_Port, Relay1_Pin, DIO_PIN_OUTPUT);
	DIO_setPinValue(Relay1_Port, Relay1_Pin, DIO_PIN_LOW);
	#elif	Relay==Relay2
	DIO_setPinDir(Relay2_Port, Relay2_Pin, DIO_PIN_OUTPUT);
	DIO_setPinValue(Relay2_Port, Relay2_Pin, DIO_PIN_LOW);
	#endif
}

void Relay_ON(uint8 Relay)
{
	#if	 Relay==Relay1
	DIO_setPinValue(Relay1_Port, Relay1_Pin, DIO_PIN_HIGH);
	#elif	 Relay==Relay2
	DIO_setPinValue(Relay2_Port, Relay2_Pin, DIO_PIN_HIGH);
	#endif
}
void Relay_OFF(uint8 Relay)
{
	#if	 Relay==Relay1
	DIO_setPinValue(Relay1_Port, Relay1_Pin, DIO_PIN_LOW);
	#elif	 Relay==Relay2
	DIO_setPinValue(Relay2_Port, Relay2_Pin, DIO_PIN_LOW);
	#endif
}

void Relay_Toggle(uint8 Relay)
{
	#if	 Relay==Relay1
	DIO_togglePin(Relay1_Port, Relay1_Pin);
	#elif	 Relay==Relay2
	DIO_togglePin(Relay2_Port, Relay2_Pin);
	#endif
}
