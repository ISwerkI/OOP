#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n---------------------------------------------------------------------------------------\n"

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
	//				Constructor
	Point()
	{
		x = y = {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "XYArgConstructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destrctor:\t" << this << endl;
	}
	//				Operators
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;

	}
	//				Metods
	double distance(const Point& other)const
	{
		//other.x *= 100;
		//other.y *= 100;
		//this->x *= 100;
		//this->y *= 100;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance+y_distance*y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << ", \tY = " << y << endl;
	}
};

double distance(Point A, Point B);

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRCTORS_CHECK
#define ASSIGNMET_CHECK
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

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << delimeter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;
	cout << delimeter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRCTORS_CHECK
	Point A;
	A.print();

	Point B = 999;
	B.print();

	Point C(111,222);
	C.print();

	Point D = C;
	D.print();

	Point E;
	E = D;
	E.print();
#endif

#ifdef ASSIGNMET_CHECK
	int a, b, c;
	a = b = c = {};
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	A = Point(2, 3);
	B = A;
	C = B;
	A.print();
	B.print();
	C.print();
#endif
}
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_y();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}