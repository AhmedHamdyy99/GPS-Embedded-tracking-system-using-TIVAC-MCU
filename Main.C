int main(void)
{
	
	
	MicroStart();
	Red_LED();
	LCD_init();
	dmilli(20);
	uart_Init();
	
	do
	{
		Receive_Str (z)	;              // TAKE FIRST POINT EXIT WHEN YOU TAKE VALID DATA
	}	while(check(z));
	
	Coord_Read(z, x , y) ;         //  CUTTING STRING AND TAKE THE LONGTIUDE AND LATITUDE 
	oldpointx  = lattitude(x);      // CONVERT   LATITUDE  TO DOUBLE 
	oldpointy =  longitude(y);      //  CONVERT   LONGTIUDE TO DOUBLE 
	
	while (1)
	{
		dmilli_break(5000);    /*  DELAY BETWEEN READING POINTS 
		AND ALSO FUNCTION WHEN SWITCH 2 PRESSED GET OUT FROM DELAY FUNCTION AND RECIEVE NEW POINT WHEN YOU CHANGE DIRECTION */
		
		do                    /* STILL IN WHILE UNTILE YOU TAKE VALID DATE*/
		{
			Receive_Str (z)	;
		}	while(check(z));
		
		Coord_Read(z, x , y) ;              //  CUTTING STRING AND TAKE THE LONGTIUDE AND LATITUDE 
		newpointx  = lattitude(x);           // CHANGE IT TO DOUBLE VALUE 
		newpointy= longitude(y);         //CHANGE IT TO DOUBLE VALUE 
		
		distance += CalcDistance(newpointx ,newpointy , oldpointx , oldpointx) ;   // INCREMENT DISTNACE BY THE NEW VALUE 
		oldpointx =  newpointx  ;               //
	  oldpointy=   newpointy;
		if ((GPIO_PORTF_DATA_R &= 0x01) == 0) // SWITCHBUTTON1 IS PRESSED  SHOW DISTANCE ON LCD 
				{
				
		double_to_String(distance , display);
   	LCD_sendCommand(CLEAR_COMMAND);				
		LCD_displayCharacter(display[0]);
		dmilli(40);
		LCD_displayCharacter(display[1]);
		dmilli(40);
		LCD_displayCharacter(display[2]);
		dmilli(40);
						
		LCD_displayString(" is distance"); ;
				}
	}
}