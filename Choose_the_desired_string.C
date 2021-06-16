int check(char* z) // FUNCTION TO TAKE THE DESIRED STRING SENT FROM GPS (STARTS WITH "$GPRMC")
{
	char chk[6] ;
	int i;
	for ( i = 0 ; i < 6 ; i ++) //GET THE FIRST CHARS "$GPRMC"
	{
		chk[i] = z[i] ;
	}
	if (!(strcmp(chk ,"$GPRMC"))) //COMPARES THE RECIEVED 6 CHRS 
	{ return 0 ;}
	else
	{return 1 ;}
	
}
