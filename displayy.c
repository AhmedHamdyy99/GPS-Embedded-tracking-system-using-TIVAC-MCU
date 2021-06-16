#include "C:\Users\user\Downloads\tm4c123gh6pm.h"
#include "C:\Users\user\Downloads\Standard_types_ARM.h"
void displayNumberOnSevenSegment(int number);
void displayNumber(int number);
int d1,d2,d3;



void displayNumberOnSevenSegment(int number) 
{ // displays a number 0-9
 if(number==0){
	 GPIO_PORTB_DATA_R=0x3F;//all on except g
 }else if(number==1){
	 GPIO_PORTB_DATA_R=0x06; //b and c on
 }else if(number==2){
	 GPIO_PORTB_DATA_R=0x5B; // a b g e d
 }else if(number==3){
	 GPIO_PORTB_DATA_R=0x4F; // a b c d g
 }else if(number==4){
	 GPIO_PORTB_DATA_R=0x66; // b c f g
 }else if(number==5){
	 GPIO_PORTB_DATA_R=0x6D; //a f g c d
 }else if(number==6){
	 GPIO_PORTB_DATA_R=0x7D; // all except b
 }else if(number==7){
	 GPIO_PORTB_DATA_R=0x07; // a b c
 }else if(number==8){
	 GPIO_PORTB_DATA_R=0x7F; // all
 }else if(number==9){
	 GPIO_PORTB_DATA_R=0x6F; // all except e
 }

 void displayNumber(int number){
/* extract each digit */
if(number==0){
		 GPIO_PORTD_DATA_R=0x03;
		     	displayNumberOnSevenSegment(0);
	 }else if(number !=0){
	 
	 

    d1 = number % 10;
    number /= 10;
    d2 = number % 10;
        number /= 10;
        d3 = number;
      
}

    while(1)//if you need to make the bonus change true 
        
		{
				
				//turning on digit one and putting right most digit in it
    	GPIO_PORTD_DATA_R=0x03;
    	displayNumberOnSevenSegment(d1);
      dimili(1);

        //turning digit two and putting the middle digit in it
      GPIO_PORTD_DATA_R=0x05;
      displayNumberOnSevenSegment(d2);
       dimili(1);
       
        //turning digit three and putting the left digit in it
       GPIO_PORTD_DATA_R=0x06;
       displayNumberOnSevenSegment(d3);
       dmili(1);

}
}
