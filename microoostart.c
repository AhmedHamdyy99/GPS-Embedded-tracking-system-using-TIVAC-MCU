void MicroStart(void){

/***************************
 *
 *        Intialisation was made for LCD  PORT A  AND PORT B AND PORT D 
 *                                          *
 ***************************/
	//    PORTA   PIN3  FOR LCD 
	 SYSCTL_RCGCGPIO_R|=0x01;                     // ENABLE CLOCK OF PORT A
while ((SYSCTL_PRGPIO_R&0x01) == 0){} ;  	     // CHECK CLOCK OF PORT A 
    GPIO_PORTA_CR_R = 0xFF;                   // ENBALE CHANGES ON PINS OF PORT A 
    GPIO_PORTA_DIR_R = 0xFF;                 // SET PORT A OUTPUTPINS 
    GPIO_PORTA_AFSEL_R = 0x00;              //DISABLE ALTERNATE FUNCTION 
    GPIO_PORTA_PCTL_R = 0x00000000;        //PORTA AS GPIO
    GPIO_PORTA_AMSEL_R = 0x00;            //DISABLE ANALOG PINS 
    GPIO_PORTA_DEN_R = 0xFF;             //ENABLE DIGITAL PINS 
	
	
	//      PORT B   FOR DATE OF LCD  
	SYSCTL_RCGCGPIO_R |= 0x02;                // ENABLE CLOCK OF PORT B
  while ((SYSCTL_PRGPIO_R&0x02) == 0){} ;  //CHECK FLAG OF PORT B
GPIO_PORTB_CR_R = 0xFF;                   // ENABLE THE CHANGES ON PINS OF PORT B
GPIO_PORTB_DIR_R = 0xFF;                 //  OUTPUTS PINS 
GPIO_PORTB_DEN_R = 0xFF;                // DIGITAL PINS 
GPIO_PORTB_AMSEL_R &= ~0xFF;           // DISABLE ANALOG SIGNAL 
GPIO_PORTB_AFSEL_R &=~0xFF;           // DISABLE ALTERNATE FUNCTION SELECTION  
GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;    // OUTPUT PINS 
GPIO_PORTB_DATA_R  =0x00;           // START WITH ZERO VALUE 
	
	
	
	
	 
	//      PORT D   FOR CONTROL OF LCD 
		SYSCTL_RCGCGPIO_R |= 0x08;             // ENABLE CLOCK OF PORT D
//while ((SYSCTL_PRGPIO_R&0x08) == 0){};  //CHECK FLAG OF PORTD 
GPIO_PORTD_CR_R |= 0xFF;                 // ENABLE THE CHANGES  ON PIN2 PIN3 PIN4  
GPIO_PORTD_DIR_R |= 0xFF;               //  OUTPUTS PINS 
GPIO_PORTD_DEN_R |= 0xFF;              // DIGITAL PINS 
GPIO_PORTD_AMSEL_R &= ~0xFF;          // DISABLE ANALOG SIGNAL 
GPIO_PORTD_AFSEL_R &=~0xFF;          // DISABLE ALTERNATE FUNCTION SELECTION  
GPIO_PORTD_PCTL_R &= ~0xFFFFFFFF;   // OUTPUT PINS 
GPIO_PORTD_DATA_R  |=0xFF;         // START WITH ZERO VALUE 
	 
 	/***************************/
	
	
}
