#pragma once
class Line
{
public:
	double a, b,delta;
	unsigned mode;

	unsigned value(double x, double y);

	Line(double a, double b, double delta, double mode);

};

