#include "distaance.h"
const double PI = 3.1415926;
double calculateDistanceBetweenLatAtit( double x1, double y1, double x2, double y2)
{
	double m;
  double L; 	
	double radius = 6371;
	double x = (x2 - x1)* PI /180;
	double y = (y2-y1)* PI /180;
	x1 =  x1 * PI /180;
	x2 = x2 * PI /180;
	m = pow(sin(x/2),2) + cos(x1)*cos(x2)*pow(sin(y/2),2);
	L = 2*radius* asin(sqrt(m));
	return L*1000;
}
