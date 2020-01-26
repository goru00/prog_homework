#include<iostream>
#include<math.h>
using namespace std;
class Complex
{
private:
	double a, b;
public:
	Complex(int m_a, int m_b) : a(m_a), b(m_b) { }
	Complex() { }
	~Complex() { }
	void division(Complex& complex1, Complex& complex2)
	{
		a = ((complex1.a * complex2.a + complex1.b * complex2.b) / (pow(complex2.a, 2) + pow(complex2.b, 2)));
		b = ((complex2.a * complex1.b - complex2.b * complex1.a) / (pow(complex2.a, 2) + pow(complex2.b, 2)));
	}
	void sum(Complex& complex1, Complex& complex2)
	{
		a = complex1.a + complex2.a;
		b = complex1.b + complex2.b;
	}
	void substract(Complex& complex1, Complex& complex2)
	{
		a = complex1.a - complex2.a;
		b = complex1.b - complex2.b;
	}
	void multiplay(Complex& complex1, Complex& complex2)
	{
		a = complex1.a * complex2.a - complex1.b * complex2.b;
		b = complex1.a * complex2.b + complex1.b * complex2.a;
	}
	void degree(Complex& complex, int value)
	{
		Complex operation;
		operation.a = sqrt(pow(complex.a, 2) + pow(complex.b, 2));
		operation.b = atan(complex.b/complex.a);
		a = operation.a * cos(value * operation.b);
		b = operation.a * sin(value * operation.b);
	}
	friend ostream& operator<<(ostream& out, const Complex& complex);
};
ostream& operator<<(ostream& out, const Complex& complex)
{
	if (complex.b > 0)
		out << complex.a << "+" << complex.b << "i";
	else out << complex.a << "" << complex.b << "i";
	return out;
}
int main()
{
	setlocale(0, "");
	Complex obj1(2, -3);
	cout << "Первое число: " << obj1 << endl;
	Complex obj2(5, 4);
	Complex obj3; // приводим к виду z=z1/z2 и т.д. тобишь в этом объекте мы храним результат работы методов.
	cout << "Второе число: " << obj2 << endl;
	obj3.degree(obj1, 20);
	cout << "Степень числа: " << obj1 << " = " << obj3 << endl;
	obj3.multiplay(obj1, obj2);
	cout << "Умножение комплексных чисел: (" << obj1 << ")*(" << obj2 << ") = " << obj3 << endl;
	obj3.substract(obj1, obj2);
	cout << "Разность комплексных чисел: " << obj1 << "-" << obj2 << " = " << obj3 << endl;
	obj3.sum(obj1, obj2);
	cout << "Сумма комплексных чисел: " << obj1 << "+" << obj2 << " = " << obj3 << endl;
	obj3.division(obj1, obj2);
	cout << "Деление комплексных чисел: (" << obj1 << ")/(" << obj2 << ") = " << obj3 << endl;
	return 0;
}