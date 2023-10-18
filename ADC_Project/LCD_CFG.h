
#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "DIO.h"


#define LCD_8BIT_CMD_PORT	DIO_PORTA
#define LCD_8BIT_DATA_PORT	DIO_PORTB

#define LCD_4BIT_CMD_PORT	DIO_PORTA
#define LCD_4BIT_DATA_PORT	DIO_PORTB

#define LCD_RS_PIN			DIO_PIN3
//#define LCD_RW_PIN
#define LCD_E_PIN			DIO_PIN2

//#define LCD_D0
//#define LCD_D1
//#define LCD_D2
//#define LCD_D3
#define LCD_D4				DIO_PIN0
#define LCD_D5				DIO_PIN1
#define LCD_D6				DIO_PIN2
#define LCD_D7				DIO_PIN4

#define LCD_MODE			4

#define DISPLAY_OFF 0
#define DISPLAY_ON 1

#define CURSOR_OFF	0
#define CURSOR_ON	1
#define CURSOR_BLINK_OFF	3
#define CURSOR_BLINK_ON		2

#endif /* LCD_CFG_H_ */