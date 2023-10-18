
#ifndef LCD_H_
#define LCD_H_
#include "STD.h"
#include "LCD_CFG.h"
#include "DIO.h"
#define F_CPU 16000000
#include <util/delay.h>

void LCD_Cursor(uint8_t Cursor_Status);
void LCD_Display(uint8_t Display_Status);
void LCD_INIT(void);
void LCD_WRITE_CMD(uint8 cmd);
void LCD_WRITE_CHAR(uint8 value);
void LOCATE_CURSOR(uint8 row,uint8 col);
void LCD_WRITE_STRING(uint8* str);
void LCD_CLR(void);
void LCD_WRITE_INTEGER(sint32 intgr);
void LCD_DRAW_STRING(uint8* str);

#endif /* LCD_H_ */