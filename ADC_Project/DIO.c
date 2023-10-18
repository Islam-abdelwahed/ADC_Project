#include "DIO.h"

void DIO_setPortDir(uint8 port,uint8 dir){
	switch(port){
		case DIO_PORTA:
		DDRA=dir;
		break;
		case DIO_PORTB:
		DDRB=dir;
		break;
		case DIO_PORTC:
		DDRC=dir;
		break;
		case DIO_PORTD:
		DDRD=dir;
		break;
		default:
		break;
	}
};

void DIO_setPortValue(uint8 port,uint8 value){
	switch(port){
		case DIO_PORTA:
		PORTA=value;
		break;
		case DIO_PORTB:
		PORTB=value;
		break;
		case DIO_PORTC:
		PORTC=value;
		break;
		case DIO_PORTD:
		PORTD=value;
		break;
		default:
		break;
	}
};

void DIO_setPinDir(uint8 port,uint8 pin,uint8 dir){
	switch(dir){
		case DIO_PIN_OUTPUT:
		{
			switch(port){
				case DIO_PORTA:
				SET_BIT(DDRA,pin);
				break;
				case DIO_PORTB:
				SET_BIT(DDRB,pin);
				break;
				case DIO_PORTC:
				SET_BIT(DDRC,pin);
				break;
				case DIO_PORTD:
				SET_BIT(DDRD,pin);
				break;
				default:
				break;
			}
		}
		break;
		case DIO_PIN_INPUT:
		{
			switch(port){
				case DIO_PORTA:
				CLR_BIT(DDRA,pin);
				break;
				case DIO_PORTB:
				CLR_BIT(DDRB,pin);
				break;
				case DIO_PORTC:
				CLR_BIT(DDRC,pin);
				break;
				case DIO_PORTD:
				CLR_BIT(DDRD,pin);
				break;
				default:
				break;
			}
		}
		break;
		default:
		break;
	}
};

void DIO_setPullUp(uint8 port,uint8 pin){
	switch(port){
		case DIO_PORTA:
		SET_BIT(PORTA,pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB,pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC,pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD,pin);
		break;
		default:
		break;
	}
	};

void DIO_setPinValue(uint8 port,uint8 pin,uint8 value){
		switch(value){
			case DIO_PIN_HIGH:
			{
				switch(port){
					case DIO_PORTA:
					SET_BIT(PORTA,pin);
					break;
					case DIO_PORTB:
					SET_BIT(PORTB,pin);
					break;
					case DIO_PORTC:
					SET_BIT(PORTC,pin);
					break;
					case DIO_PORTD:
					SET_BIT(PORTD,pin);
					break;
					default:
					break;
				}
			}
			break;
			case DIO_PIN_LOW:
			{
				switch(port){
					case DIO_PORTA:
					CLR_BIT(PORTA,pin);
					break;
					case DIO_PORTB:
					CLR_BIT(PORTB,pin);
					break;
					case DIO_PORTC:
					CLR_BIT(PORTC,pin);
					break;
					case DIO_PORTD:
					CLR_BIT(PORTD,pin);
					break;
					default:
					break;
				}
			}
			break;
			default:
			break;
		}
};

void DIO_readPinValue(uint8 port,uint8 pin,uint8* value){
	switch(port){
		case DIO_PORTA:
		*value=GET_BIT(PINA,pin);
		break;
		case DIO_PORTB:
		*value=GET_BIT(PINB,pin);
		break;
		case DIO_PORTC:
		*value=GET_BIT(PINC,pin);
		break;
		case DIO_PORTD:
		*value=GET_BIT(PIND,pin);
		break;
		default:
		break;
	}
};

void DIO_readPortValue(uint8 port,uint8* value){
	switch(port){
		case DIO_PORTA:
		*value=PINA;
		break;
		case DIO_PORTB:
		*value=PINB;
		break;
		case DIO_PORTC:
		*value=PINC;
		break;
		case DIO_PORTD:
		*value=PIND;
		break;
		default:
		break;
	}
};

void DIO_togglePin(uint8 port,uint8 pin){
	switch(port){
		case DIO_PORTA:
		TOGGLE_BIT(PORTA,pin);
		break;
		case DIO_PORTB:
		TOGGLE_BIT(PORTB,pin);
		break;
		case DIO_PORTC:
		TOGGLE_BIT(PORTC,pin);
		break;
		case DIO_PORTD:
		TOGGLE_BIT(PORTD,pin);
		break;
		default:
		break;
	}
};


