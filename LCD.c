#include "LCD.h"
/* data on Port D */
/* control by Port C */

void LCD_init(void)
{

	SYSCTL_RCGCGPIO_R |=0x0C;//activate the clock for Port C, D.
	//while((BIT_IS_CLEAR(SYSCTL_PRGPIO_R,2))&&(BIT_IS_CLEAR(SYSCTL_PRGPIO_R,3)));
   //OR Delay instead of While

//*****************************************************************************
//
// PORTD and PORTE configuration (Data Port PD0,PD1,PD2,PD3,PD6,PD7,PE2,PE3)
//
//*****************************************************************************
	GPIO_PORTD_LOCK_R =0x4C4F434B; //unlock PD7
	SET_BIT(GPIO_PORTD_AHB_CR_R,PD7) ;//unlock PD7
	GPIO_PORTD_AMSEL_R =0x00;//disable analog signal for PORT D
	GPIO_PORTD_PCTL_R =0x00000000; // PORT D is regular functioned
	GPIO_PORTD_AFSEL_R =0x00;// PORT D is input/output PORT
	LCD_DATA_PORT_DIR = 0xFF; /* Configure the DPORT as output data port */ 
	LCD_DATA_PORT_DEN =0xFF; /*all sent data is digital in PORTD*/
	GPIO_PORTE_AMSEL_R &=~(0x0C);//disable analog signal for PORT PE2,PE3
	GPIO_PORTE_PCTL_R &=~0x0000FF00; // PORT E is regular functioned
	GPIO_PORTE_AFSEL_R &=~0x0C;// PORT E is input/output PORT
	LCD_DATA_PORT_DIR |= 0x0C; /* Configure the PORTE PE2,PE3 as output data port */
	LCD_DATA_PORT_DEN =0xFF; /*all sent data is digital in PORTE*/

//*****************************************************************************
//
// PORTC configuration (control Port)
//
//*****************************************************************************
	GPIO_PORTC_AHB_AMSEL_R &=0x8F;//disable analog signal for PORT C(PC4,PC5,PC6)
	GPIO_PORTC_AHB_PCTL_R &=0xF000FFFF; // PORT C(PC4,PC5,PC6) is regular functioned
	GPIO_PORTC_AHB_AFSEL_R &=0x8F;// PORT C is input/output PORT
	LCD_CTRL_PORT_DIR |= (1<<E) | (1<<RS) | (1<<RW); /* Configure the control pins(E,RS,RW) as output pins */
	LCD_CTRL_PORT_DEN |= (1<<E) | (1<<RS) | (1<<RW);/* all control bits are digital*/



	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */

	LCD_sendCommand(CURSOR_OFF); /* cursor off */

	LCD_sendCommand(CLEAR_COMMAND);// clear screen 
}


