#include "LCD.h"
/* data on Port B */
/* control by Port D */

void dmilli_break(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<3180;j++)
	{}
if((GPIO_PORTF_DATA_R &(1<<4))==0){
	break;
}
}
}
void dmilli(int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<3180;j++)
	{}

}


void LCD_init(void)
{
    
        LCD_sendCommand(wake_up);
    
dmilli(30);
    LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); // use 2-line lcd + 8-bit Data Mode  
dmilli(30);
    LCD_sendCommand(CURSOR_OFF); // cursor off 
dmilli(30);
    LCD_sendCommand(CLEAR_COMMAND);// clear screen 

dmilli(30);
    LCD_sendCommand(AUTO_INCREMENT);//auto increment
    dmilli(30);
    LCD_sendCommand(display_on);//display
    
}

void LCD_sendCommand(uint8_t command)
{
    CLEAR_BIT(LCD_CTRL_PORT,RS); // Instruction Mode RS=0 
    CLEAR_BIT(LCD_CTRL_PORT,RW); // write data to LCD so RW=0 
    dmilli(30); // delay for processing 
    SET_BIT(LCD_CTRL_PORT,E); // Enable LCD E=1 
    dmilli(30); // delay for processing  
    LCD_DATA_PORT = command; // out the required command to the data bus D0 --> D7 
    dmilli(30); // delay for processing Tds
    CLEAR_BIT(LCD_CTRL_PORT,E); // disable LCD E=0 
    dmilli(30); // delay for processing  
}
void LCD_displayCharacter(unsigned char data)
{
    if(data & 0x40) GPIO_PORTA_DATA_R |=(0x08);
    
   
    
    SET_BIT(LCD_CTRL_PORT,RS); // Data Mode RS=1 
    CLEAR_BIT(LCD_CTRL_PORT,RW); // write data to LCD so RW=0 /
    dmilli(30); // delay for processing  /
    SET_BIT(LCD_CTRL_PORT,E); // Enable LCD E=1 /
    dmilli(30); // delay for processing  /
    LCD_DATA_PORT = data; // out the required data char to the data bus D0 --> D7 /
    dmilli(30); //delay for processing  /
    CLEAR_BIT(LCD_CTRL_PORT,E); // disable LCD E=0 /
    dmilli(30); // delay for processing  */
}

void LCD_displayString(const char *Str)
{
    uint8_t i = 0;
    while(Str[i] != '\0')
    {

        LCD_displayCharacter(Str[i]);
        dmilli(30);
    //    LCD_sendCommand(AUTO_INCREMENT);
    
        i++;
        dmilli(30);
    }

}

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display 
}
