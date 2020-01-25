#include<iostream>
using namespace std;
class Fraction
{
private:
	__int64 num1; unsigned __int16 num2; 
public:
	Fraction(__int64 m_num1, unsigned __int16 m_num2)
	{
		num1 = m_num1;
		num2 = m_num2;
	}
	Fraction() {}
	~Fraction() {}
	friend Fraction operator+=(const Fraction &fraction1, const Fraction &fraction2);
	friend Fraction operator-(const Fraction &fraction1, const Fraction &fraction2);
	friend ostream& operator<<(ostream &out, const Fraction &fraction);
};
ostream& operator<<(ostream &out, const Fraction &fraction)
{
	out << fraction.num1 << "/" << fraction.num2 << endl;
	return out;
}
Fraction operator+=(const Fraction &fraction1, const Fraction &fraction2)
{
	Fraction fraction1.num1 += fraction2.num1;
	return fraction1.num1;
}
Fraction operator-(const Fraction &fraction1, const Fraction &fraction2)
{
	return (fraction1 - fraction2);
}
int main()
{
	setlocale(0, "");
	Fraction obj1(-2, 4);
	Fraction obj2(-3, 5);
	obj1 += obj2;
	cout << "Сложение дробей: " << obj1 << " + " << obj2 << "\t = ";
	obj1 -= obj2;
	cout << "Вычитание дробей: " << obj1 << " - " << obj2 << "\t = ";
	return 0;
}
