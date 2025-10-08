#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance_x(double x,double coordinates)
	{
		double distance;
		distance = coordinates + x;
		return distance;
	}
	double distance_y(double y, double coordinates)
	{
		double distance;
		distance = coordinates + y;
		return distance;
	}
	double distance_xy(double x, double y)
	{
		double distance;
		if (x < 0) x *= -1;
		if (y < 0) y *= -1;
		distance = x + y;
		return distance;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	cout << "Hello OOP!" << endl;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif

	Point A;
	A.set_x(2);
	A.set_y(3);
	double distance_x=A.distance_x(5, 0);
	double distance_y = A.distance_y(5, 0);
	double distance_xy = A.distance_xy(5, -5);
	cout << A.get_x() << "\t" << A.get_y()<< endl;
	cout << distance_x << "\t" << distance_y <<"\t"<<distance_xy<< endl;
}