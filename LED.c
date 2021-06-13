void Red_LED (void)    // ENBALE ALL LED AT PORT F  AND SWITCHES INTLIAZE THEM WITH ZEROO
{
SYSCTL_RCGCGPIO_R |= 0x20;                        // ENABLE CLOCK OF PORT F
while ((SYSCTL_PRGPIO_R&0x20) == 0){} ;          //CHECK FLAG
GPIO_PORTF_LOCK_R = 0x4C4F434B;                 // UNLOCK PORT  F
GPIO_PORTF_CR_R |= 0x1F;                       // ENABLE THE CHANGES  
GPIO_PORTF_DIR_R |= 0X0E;                     //  OUTPUTS PINS 
GPIO_PORTF_DEN_R |= 0x0E;                    // DIGITAL PINS 
GPIO_PORTF_AMSEL_R &= ~0x0E;                // DISABLE ANALOG SIGNAL 
GPIO_PORTF_AFSEL_R &=~0x0E;                // DISABLE ALTERNATE FUNCTION SELECTION  
GPIO_PORTF_PCTL_R &= ~0x000FFFFF;         // OUTPUT PINS 
GPIO_PORTF_DATA_R &= ~0x0F;              // INTILZIE THEM 
GPIO_PORTD_PUR_R =0x11;	                // ACTIVATE PULL UP RESISTOR 
}

 void LED_ON()
{
	GPIO_PORTF_DATA_R |= (1<<2);       // BLUE LED ON    
}
