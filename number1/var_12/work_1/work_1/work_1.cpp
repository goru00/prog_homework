#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Point
{
private:
	int x, y;
	string point_name;
public:
	Point(string _point_name, int _x, int _y) : point_name(_point_name), x(_x), y(_y) { }
	Point() : point_name(""), x(0), y(0) { }
	~Point() { }
	double _long(Point&, Point&);
	double _long(Point&);
	friend ostream& operator<<(ostream&, const Point&);
};
class Triangle : public Point
{
private:
	Point A, B, C;
	string point_name;
public:
	Triangle(string _point_name, Point _A, Point _B, Point _C) : point_name(_point_name), A(_A), B(_B), C(_C) { }
	Triangle(Triangle &t) : point_name(t.point_name), A(t.A), B(t.B), C(t.C) { }
	double perimetr();
	double area();
};
double Point::_long(Point& A, Point& B) { return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2)); }
double Point::_long(Point& A) { return sqrt(pow(x - A.x, 2) + pow(A.y - y, 2)); }
double Triangle::perimetr() { return A._long(B) + _long(B, C) + _long(C, A); }
double Triangle::area()
{
	double d = (_long(A, B) + _long(B, C) + _long(C, A))/2;
}
ostream& operator<<(ostream& out, const Point& p)
{
	out.width(5);
	out << p.point_name << p.x << p.y << endl;
	return out;
}
int main()
{
	setlocale(0, "");
	return 0;
}