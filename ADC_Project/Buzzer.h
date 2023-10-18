
#ifndef LED_H_
#define LED_H_

#include "DIO.h"
#include "Buzzer_Cfg.h"
#define F_CPU 16000000
#include <util/delay.h>


void BUZZER_Init(void);
void BUZZER_Status(uint8 Buz_sta);
void BUZZER_Toggle(void);
void BUZZER_SHORT_BEEP(void);
void BUZZER_LONG_BEEP(void);
void BUZZER_BEEP_BEEP(void);


#endif 