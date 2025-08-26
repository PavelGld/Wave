#include "Line.h"
#include "math.h"
#define M_PI 3.1415926535

unsigned Line::value(double x, double y)
{
	if (((x < 0) || (x > 1)) || ((y < 0) || (y > 1)))
		return 0;

	if (mode == 0)
	{
		if ((a*x + b - y)*(a*x + b - y) <= delta)
			return 1;
		else
			return 0;
	}
	if (mode == 1)
	{
		if ((a - x)*(a - x) <= delta)
			return 1;
		else
			return 0;
	}
	if (mode == 2)
	{
		if ((a - y)*(a - y) <= delta)
			return 1;
		else
			return 0;
	}
	if (mode == 3)// полукруг окружности
	{
		double tru_x(x-0.5), tru_y(y-0.5);
		double r(sqrt(tru_x*tru_x + tru_y * tru_y)),phi(0);
		if (r > delta)
			return 0;

		phi = atan2(tru_y,tru_x);
		if ((a < phi)&&(phi<b))
			return 0;
		else
			return 1;


	}
}

Line::Line(double a, double b, double delta, double mode)
{
	this->a = a;
	this->b = b;
	this->delta = delta;
	this->mode = mode;
}