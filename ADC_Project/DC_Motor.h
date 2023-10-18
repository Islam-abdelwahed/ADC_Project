#ifndef DC_MOTO_H_
#define DC_MOTO_H_
//#include "Timer.h"
#include "DIO.h"

typedef enum{
	CLOCK_WISE_DIR,
	ANTI_CLOCK_WISE_DIR
	}DC_MOTOTR_DIR;

void DCMotor_Init(void);

void DCMotor_SetSpeed(uint8 speed);

void DCMotor_SetDir(DC_MOTOTR_DIR Dir);

void DCMotr_Start(void);

void DCMotr_Stop(void);


#endif /* DC_MOTO_H_ */