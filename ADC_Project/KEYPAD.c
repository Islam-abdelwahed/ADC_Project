

#include "KEYPAD.h"


const uint8 keypadValues[4][4]={
	{ '7', '8', '9', ':'},
	{ '4', '5', '6', ':'},
	{ '1', '2', '3', ':'},
	{ 'c', '0', '=', ':'}
};

void KEYPAD_INIT(void){
	
	DIO_setPinDir(KEYPAD_COL_PORT,KEYPAD_COL1,DIO_PIN_OUTPUT);
	DIO_setPinDir(KEYPAD_COL_PORT,KEYPAD_COL2,DIO_PIN_OUTPUT);
	DIO_setPinDir(KEYPAD_COL_PORT,KEYPAD_COL3,DIO_PIN_OUTPUT);
	DIO_setPinDir(KEYPAD_COL_PORT,KEYPAD_COL4,DIO_PIN_OUTPUT);
	
	DIO_setPinDir(KEYPAD_ROW_PORT,KEYPAD_ROW1,DIO_PIN_INPUT);
	DIO_setPinDir(KEYPAD_ROW_PORT,KEYPAD_ROW2,DIO_PIN_INPUT);
	DIO_setPinDir(KEYPAD_ROW_PORT,KEYPAD_ROW3,DIO_PIN_INPUT);
	DIO_setPinDir(KEYPAD_ROW_PORT,KEYPAD_ROW4,DIO_PIN_INPUT);
	
	DIO_setPullUp(KEYPAD_ROW_PORT,KEYPAD_ROW1);
	DIO_setPullUp(KEYPAD_ROW_PORT,KEYPAD_ROW2);
	DIO_setPullUp(KEYPAD_ROW_PORT,KEYPAD_ROW3);
	DIO_setPullUp(KEYPAD_ROW_PORT,KEYPAD_ROW4);
	
	DIO_setPinValue(KEYPAD_COL_PORT,KEYPAD_COL1,DIO_PIN_HIGH);
	DIO_setPinValue(KEYPAD_COL_PORT,KEYPAD_COL2,DIO_PIN_HIGH);
	DIO_setPinValue(KEYPAD_COL_PORT,KEYPAD_COL3,DIO_PIN_HIGH);
	DIO_setPinValue(KEYPAD_COL_PORT,KEYPAD_COL4,DIO_PIN_HIGH);
	
};
uint8 keypadGetValue(void){
	
	uint8 LOC_Column = 0;
	uint8 LOC_Row = 0;
	uint8 Value = 0;
	uint8 Temp = 0;
	uint8 specialcase = 0;
	for( LOC_Column = Col_INIT ; LOC_Column >= Col_FINAL ; LOC_Column-- ) //Decrement Because of ports [7 -> 2]
	{
		if(LOC_Column == 4)
		{
			continue;
		}else if(LOC_Column == 3)
		{
			specialcase = 1;
		}
		
		DIO_setPinValue(KEYPAD_COL_PORT, LOC_Column, DIO_PIN_LOW);
		
		for( LOC_Row = Row_INIT ; LOC_Row >= Row_FINAL ; LOC_Row-- )
		{
			DIO_readPinValue(KEYPAD_ROW_PORT, LOC_Row, &Temp);
			
			if(!Temp)
			{
				Value = keypadValues[Row_INIT - LOC_Row][Col_INIT - LOC_Column - specialcase];
				
				while(!Temp)
				{
					DIO_readPinValue(KEYPAD_ROW_PORT, LOC_Row, &Temp);
				}
				
				_delay_ms(10);//Solving Bouncing Problem ( DeBouncing )
				
			}
		}
		
		DIO_setPinValue(KEYPAD_COL_PORT, LOC_Column, DIO_PIN_HIGH);
	}
	return Value;
};

