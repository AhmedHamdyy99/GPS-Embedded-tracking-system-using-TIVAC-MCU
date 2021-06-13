double longitude(char* x) // TO CALCULATE THE LONGITUDE
{   
    double sum = 0;
    double sumI = 0 ;
    sumI +=  (x[0] - '0') * 10 ;
    sumI +=  (x[1] - '0') * 1 ;
    
    
		sum += (x[2] - '0')    * 10 ;
		sum += (x[3] - '0')    * 1 ;
		sum += (x[5] - '0')    * 0.1 ;
		sum += (x[6] - '0')    * 0.01 ;
  
  return sumI + sum/60 ;
}
double lattitude(char* x) // TO CALCULATE THE LATTITUDE
{   
    double sum = 0;
    double sumI = 0 ;
    sumI +=  (x[0] - '0') * 100 ;
    sumI +=  (x[1] - '0') * 10 ;
    sumI +=  (x[2] - '0') * 1 ;
    
		sum += (x[3] - '0')    * 10 ;
		sum += (x[4] - '0')    * 1 ;
		sum += (x[6] - '0')    * 0.1 ;
		sum += (x[7] - '0')    * 0.01 ;
  
		return sumI + sum/60 ;
}
