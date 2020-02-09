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
	bool operator==(const Point&);
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
	double height(Point&);
	double angle(Point &);
	void compare(Point&, Point&, Point&);
	void sort(const unsigned int, double*);
	friend ostream& operator<<(ostream&, const Triangle&);
};
double Point::_long(Point& A, Point& B) { return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2)); }
double Point::_long(Point& A) { return sqrt(pow(x - A.x, 2) + pow(A.y - y, 2)); }
bool Point::operator==(const Point& A) { return (A.x == x && A.y == y); }
double Triangle::perimetr() { return A._long(B) + _long(B, C) + _long(C, A); }
double Triangle::area()
{
	double d = (_long(A, B) + _long(B, C) + _long(C, A))/2;
	return sqrt(d * (d - _long(A, B)) * (d - _long(B, C)) * (d - _long(C, A)));
}
double Triangle::height(Point &D)
{
	double result;
	if (A == B) result = _long(B, C);
	else if (B == D) result = _long(A, C);
	else result = _long(A, B);
	return 2 * area() / result;
}
double Triangle::angle(Point& D)
{
	double result, prev;
	if (A == D) {
		result = height(B);
		prev = _long(A, B);
	}
	else if (B == D) {
		result = height(C);
		prev = _long(B, C);
	} else {
		result = height(A);
		prev = _long(A, C);
	}
	return sin(result / prev);
}
void Triangle::compare(Point &A1, Point &B1, Point &C1)
{
	const unsigned int I = 3;
	double figure_1[I] = { _long(A, B), _long(B, C), _long(C, A) };
	double figure_2[I] = { _long(A1, B1), _long(B1, C1), _long(C1, A1) };
	sort(I, figure_1); sort(I, figure_2);
	int k = 0;
	for (int i = 0; i < I;) {
		if (figure_1[i] == figure_2[i]) k++;
	}
	if (k == 3) cout << "Треугольники равны\n";
	else cout << "Треугольники не равны\n";
	if (figure_1[0] / figure_2[0] == figure_1[1] / figure_2[1] && figure_1[1] / figure_2[1] == figure_1[2] / figure_2[2] && figure_1[2] / figure_2[2] == figure_1[0] / figure_2[0])
		cout << "Треугольники подобны\n";
	else cout << "Треугольники не подобны\n";
}
void Triangle::sort(const unsigned int I, double *mass)
{
	for (int i = 0; i < I; i++) {
		for (int j = 0; j < I - 1; j++) {
			if (mass[i] > mass[i + 1]) {
				double flag = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = flag;
			}
		}
	}
}
ostream& operator<<(ostream& out, const Point& p)
{
	out.width(5);
	out << endl << p.point_name << ": " << p.x << " " << p.y << endl;
	return out;
}
ostream& operator<<(ostream& out, const Triangle& p)
{
	out.width(5);
	out << p.point_name << ": " << p.A << " " << p.B << " " << p.C << endl;
	return out;
}
int main()
{
	setlocale(0, "");
	Point A("A", 5, 6);
	Point B("B", 3, 7);
	Point C("C", 2, 4);
	Triangle ABC("ABC", A, B, C);
	Point A1("A1", 10, 12);
	Point B1("B1", 6, 14);
	Point C1("C1", 4, 8);
	Triangle A1B1C1("A1B1C1", A1, B1, C1);
	Triangle D = ABC;
	cout << "Треугольник " << ABC;
	cout << "Треугольник " << A1B1C1;
	cout << "Периметр ABC: " << ABC.perimetr() << endl;
	cout << "Площадь ABC: " << ABC.area() << endl;
	cout << "Высота точки A в ABC: " << ABC.height(A) << endl;
	cout << "Угол точки B в ABC: " << ABC.angle(B) << endl;
	ABC.compare(A1, B1, C1);
	return 0;
}