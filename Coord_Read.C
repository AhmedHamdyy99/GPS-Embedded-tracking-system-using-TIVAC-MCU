void Coord_Read(char* z , char* x , char* y)// CHOOSE FROM THE RECEIVED STRING THE LATTITUDE AND LONGITUDE
{
	int q = 0;
	int i;
	for (i = 0; i < 68; i++)
	{

		if(z[i] == ',')  //COUNT COMMAS ','
		{
			int l ;
			q ++ ;
			if(q == 3) // SINCE LATTITUDE STARS AFTER THE FORTH COMMA ','
			for( l = 0 ; l < 9 ; l ++)
			{
				x[l] = z[i+l+1] ;
			}
			
			if(q == 5)
			{ 
					
					int l;
				for( l = 0 ; l < 10 ; l ++)
				{
					y[l] = z[i+l+1] ;
				}
				break ; // WE DONT' NEED THE REST OF THE STRING ONLY INTERESTED IN LATTITUDE & LONGITUDE
			}
		}
	}
	
}