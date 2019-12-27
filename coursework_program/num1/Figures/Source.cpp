#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h> 
using namespace std;

class Figure
{
protected:
	double x_center, y_center;
public:
	Figure()
	{
		x_center = y_center = 0;
	}
	Figure(double x, double y)
	{
		x_center = x;
		y_center = y;
	}
	void Move(double distance, int angle)
	{
		x_center += distance*cos(angle);
		y_center += distance*sin(angle);
	}
	virtual void Rotate(double x0, double y0, int angle) 
	{
		x_center = x0 + (x_center - x0) * cos(angle) - (y_center - y0) * sin(angle);
		y_center = y0 + (y_center - y0) * cos(angle) + (x_center - x0) * sin(angle);
	}
	virtual void Print() 
	{
		cout << "����������(" << x_center << ", " << y_center << ")\n";
	}
};

class Ellipse : public Figure
{
private:
	double radius;
public:
	Ellipse(double x, double y, double r) :Figure(x, y)
	{
		radius = r;
	}
	void Print()
	{
		cout << "������: �����(" << x_center << ", " << y_center << "), ������: " << radius << "\n";
	}
};

class Rect : public Figure
{
private:
	double width, height;
public:
	Rect(double x, double y, double w, double h) :Figure(x, y)
	{
		width = w;
		height = h;
	}
	void Print()
	{
		cout << "�������������: ����������(" << x_center << ", " << y_center << "), ������: " << width <<
			", ������: " << height << "\n";
	}
};

class RightTriangles : public Figure
{
private:
	double width, height;
public:
	RightTriangles(double x, double y, double w, double h) :Figure(x, y)
	{
		width = w;
		height = h;
	}
	void Print()
	{
		cout << "������������ �����������: ����������(" << x_center << ", " << y_center << "), ������: " << width <<
			", ������: " << height << ", ���������: " << Diagonal() << "\n";
	}
	double Diagonal()
	{
		return sqrt(width*width + height*height);
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	const int size = 4;
	Figure *figures[size];
	figures[0] = new Figure(3.3, 5.5);
	figures[1] = new Rect(4, 5, 3, 3);
	figures[2] = new RightTriangles(-66.4, -99, 89, 1024);
	figures[3] = new Ellipse(-10, -9.5, 10);
	cout << "������ ������:\n";
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". ";
		figures[i]->Print();
		figures[i]->Move(-43, -23);
		figures[i]->Rotate(0, 9, 45);
	}
	cout << "\n\n������ ����� ����������� � ��������: \n";
	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". ";
		figures[i]->Print();
	}
	_getch();
	return 0;
}