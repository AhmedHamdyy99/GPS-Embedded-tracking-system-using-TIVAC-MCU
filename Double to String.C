void double_to_String(double distance , char* array) // CONVERTS THE CALCULATED DISTANCE TO ARRAY TO DISPLAY IT ON LCD
{
		int i ;
		for(i=2;i>=0;i--)
	{

		array[i]= ((int)distance %10) + '0' ;
		distance/=10;

	}
}
