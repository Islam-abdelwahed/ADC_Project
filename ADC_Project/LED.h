#ifndef LED_H_
#define LED_H_

#include "DIO.h"
#include "STD.h"

typedef enum {
	RED_LED,
	GREEN_LED,
	BLUE_LED,
	YELLOW_LED
	}LED_COLOR;

void LED_Init(LED_COLOR Color);
void LED_ON(LED_COLOR Color);
void LED_OFF(LED_COLOR Color);
void LED_Toggle(LED_COLOR Color);


#endif /* LED_H_ */