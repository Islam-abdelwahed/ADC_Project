

#ifndef RELAY_H_
#define RELAY_H_
#include "Relay_Cfg.h"

#define Relay1		0
#define Relay2		1

// Relay Functions
void Relay_Init(uint8 Relay);
void Relay_ON(uint8 Relay);
void Relay_OFF(uint8 Relay);
void Relay_Toggle(uint8 Relay);

#endif /* RELAY_H_ */