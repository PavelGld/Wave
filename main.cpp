#include <iostream>
#include "Line.h"
#include <vector>
#include <fstream>

#define M_PI 3.1415926535

using namespace std;

vector<Line> Lines = {};
double Bx(1), By(1);
double num_p(1000);
double dx(Bx/num_p), dy(By/num_p);

unsigned G(double x, double y)
{
	for (unsigned i=0;i<Lines.size();i++)
	{
		if (Lines[i].value(x, y) == 1)
			return 1;
	}
	return 0;
}

double wave(double x, double y)
{
	return x * y*exp(-0.5*(x*x + y * y));
}

double wave_abw(double x, double y,double a, double b1, double b2, double w)
{
	double x1=1/a*(cos(w)*(x-b1)+sin(w)*(y - b2));
	double x2 = 1 / a * (-sin(w)*(x - b1) + cos(w)*(y - b2));
	return 1 / a * wave(x1, x2);
}

double W(double a, double b1, double b2, double w)
{
	double sum(0);
	for (double x=0;x<=Bx;x+=dx)
	{
		for (double y = 0; y <= By; y += dy)
		{
			if (G(x, y) == 1)
				sum += dx*dy*wave_abw(x, y, a, b1, b2, w);
		}
	}
	return sum;
}

int main()
{
	unsigned n = 3;

	/// пикча 1
	/*
	double delta(0.025);
	delta *= delta;// для выравнивания размерностей в сравнении
	/// границы по x
	Lines.push_back(Line(Bx,0,delta,1));
	Lines.push_back(Line(0,0, delta, 1));
	// границы по y
	Lines.push_back(Line(By, 0, delta, 2));
	Lines.push_back(Line(0, 0, delta, 2));
	
	
	Lines.push_back(Line(1, -By / 3, delta, 0));
	Lines.push_back(Line(1, -2 * By / 3, delta, 0));
	Lines.push_back(Line(1, 0, delta, 0));
	Lines.push_back(Line(1, By/3, delta, 0));
	Lines.push_back(Line(1, 2 * By / 3, delta, 0));

	Lines.push_back(Line(Bx/3, 0, delta, 1));
	Lines.push_back(Line(2 * Bx / 3, 0, delta, 1));
	*/

	/// пикча 2
	
	double delta(0.3);
	Lines.push_back(Line(-M_PI, 2*M_PI / 3, delta, 3));
	//Lines.push_back(Line(-M_PI, -M_PI + 3*M_PI/4, delta, 3));
	






	std::ofstream out;
	out.open("C:\\Users\\Pavel\\Desktop\\newfolder\\picture.txt");
	double di(0.01);
	for (double chx = 0; chx <= Bx; chx += di)
	{
		for (double chy = 0; chy <= By; chy += di)
		{
			out << G(chx, chy);
			if (chy <  By)
				out << "	";
			//if ((sqrt((chx - 0.5)*(chx - 0.5) + (chy - 0.5)*(chy - 0.5)) < 0.3) && (G(chx, chy) != 1))
				//cout << G(chx, chy);

		}
		cout << (chx / Bx) * 100 << endl;
		if (chx< Bx)
			out << endl;
	}
	out.close();

	
	out.open("C:\\Users\\Pavel\\Desktop\\newfolder\\diag.txt");
	for (double chx = 0; chx <= Bx; chx += di)
	{
		for (double chy = 0; chy <= By; chy += di)
		{
			out << W(0.025, chx, chy, 1.06186); //W(0.025, chx, chy, M_PI / 4); //W(0.025, chx, chy, teta);//G(chx, chy);//W(1, chx, chy, 0);
			if (fabs(chy - By) > di)
				out << "	";
		}
		cout << (chx / Bx) * 100 << endl;
		if (fabs(chx - Bx) > di)
			out << endl;
	}
	out.close();
	
	/*
	out.open("C:\\Users\\Pavel\\Desktop\\newfolder\\graph.txt");
	for (double angle = 0; angle <= 2 * M_PI; angle += 2 * M_PI / num_p)
	{
		out << W(0.025, 0.5, 0.5, angle);
		if (fabs(angle- 2 * M_PI)> 2 * M_PI / num_p)
			out<< "	";
		cout << angle / (2 * M_PI) << endl;
	}
	out.close();
	*/

	return 1;
}