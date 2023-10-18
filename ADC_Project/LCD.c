
#include "LCD.h"

uint8_t B_LCDDispControl=0b00001000;


void LCD_INIT(void){
	#if LCD_MODE == 4
	
	PORTA |= 0B00001100; DDRA |= 0B00001100;
	PORTB|=0B00010111;DDRB|=0B00010111;
	
	
	DIO_setPinDir(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
  //DIO_setPinDir(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D4,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D5,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D6,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D7,DIO_PIN_OUTPUT);
	LCD_WRITE_CMD(0x02);
	LCD_WRITE_CMD(0x28);
	LCD_Cursor(CURSOR_OFF);
	LCD_Cursor(CURSOR_BLINK_OFF);
	LCD_Display(DISPLAY_ON);
	LCD_WRITE_CMD(0x06);
	LCD_CLR();
	
	#elif LCD_MODE==8
	DIO_setPinDir(LCD_8BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_8BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
  //DIO_setPinDir(LCD_8BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_setPortDir(LCD_8BIT_CMD_PORT,DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	#endif

};


void LCD_WRITE_CMD(uint8 cmd){
	
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D4,((cmd>>4)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D5,((cmd>>5)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D6,((cmd>>6)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D7,((cmd>>7)&1));
	//PORTB=( (cmd >> 4) & 0x07) |( (cmd>>3) & 0x10) ;
	
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	_delay_us(1);

	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D4,((cmd)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D5,((cmd>>1)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D6,((cmd>>2)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D7,((cmd>>3)&1));
	
	//PORTB= (cmd & 0x07) |( (cmd<<1) & 0x10) ;

	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	_delay_us(1);
	
	_delay_us(50);
	
};


void LCD_WRITE_CHAR(uint8 value){
	
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D4,((value>>4)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D5,((value>>5)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D6,((value>>6)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D7,((value>>7)&1));
	//PORTB=( (cmd >> 4) & 0x07) |( (cmd>>3) & 0x10) ;
	
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	_delay_us(1);

	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D4,((value)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D5,((value>>1)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D6,((value>>2)&1));
	DIO_setPinValue(LCD_4BIT_DATA_PORT,LCD_D7,((value>>3)&1));
	
	//PORTB= (cmd & 0x07) |( (cmd<<1) & 0x10) ;

	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	_delay_us(1);
	
	_delay_us(50);

};
void LOCATE_CURSOR(uint8 row,uint8 col){

	uint8 pos[4]={0x80,0xC0,0x94,0xD4};
	LCD_WRITE_CMD(pos[row]+col);

};
void LCD_WRITE_STRING(uint8* str){

	int i=0;
	while( str[i] != '\0' ){
		LCD_WRITE_CHAR( str[i] );
		i++;
	}
	
};
void LCD_CLR(void){
	LCD_WRITE_CMD(0x01);
	_delay_ms(10);
};

void LCD_Display(uint8_t B_B)
{
	if (B_B==0)B_LCDDispControl&=0b11111011;		// Display off
	else if (B_B==1)B_LCDDispControl|=0b00000100;	// Display on
	LCD_WRITE_CMD(B_LCDDispControl);
}

//========================================================
void LCD_Cursor(uint8_t B_B)
{
	if (B_B==0)B_LCDDispControl&=0b11111101;		// Cursor off
	else if (B_B==1)B_LCDDispControl|=0b00000010;	// Cursor on
	else if (B_B==2)B_LCDDispControl|=0b00000001;	// Cursor blink on
	else if (B_B==3)B_LCDDispControl&=0b11111110;	// Cursor blink off
	LCD_WRITE_CMD(B_LCDDispControl);
}

void LCD_WRITE_INTEGER(sint32 intgr){
	sint32 y=1;
	if(intgr<0){
		LCD_WRITE_CHAR('-');
		intgr*=-1;
	}
	while(intgr>0)
	{
		y=((y*10)+(intgr%10));
		intgr/=10;
	}
	
	while(y>1){
		LCD_WRITE_CHAR(((y%10)+48));
		y/=10;
	}
	};
	
	void LCD_DRAW_STRING(uint8* str){
		int i=0;
		while( str[i] != '\0' ){
			LCD_WRITE_CHAR( str[i] );
			_delay_ms(100);
			i++;
		}
	}