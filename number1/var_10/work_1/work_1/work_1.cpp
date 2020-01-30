#include<iostream>
#include<cassert>
using namespace std;
class Fraction
{
private:
	int denominator, numerator;
public:
	Fraction() { }
	Fraction(int, int);
	~Fraction() { }
	double sum(Fraction&);
	double substract(Fraction&);
	double multiplication(Fraction&);
	double division(Fraction&);
	bool comparison(Fraction&);
	friend ostream& operator<<(ostream&, const Fraction&);
	// написал просто для проверки равенства. но можно было все в метод один запихнуть, но я бака!
	friend bool operator==(const Fraction&, const Fraction&);
};
Fraction::Fraction(int m_numerator, int m_denominator) 
{
	numerator = m_numerator;
	denominator = m_denominator;
}
double Fraction::sum(Fraction& fraction2) 
{ 
	return (numerator / denominator + fraction2.numerator / fraction2.denominator); 
}
double Fraction::substract(Fraction& fraction2) 
{ 
	return (numerator / denominator - fraction2.numerator / fraction2.denominator); 
}
bool Fraction::comparison(Fraction& fraction2) 
{ 
	if ((numerator / denominator) > (fraction2.numerator / fraction2.denominator)) return true; 
}
double Fraction::division(Fraction& fraction2) { 
	return ((numerator / denominator) / (fraction2.numerator / fraction2.denominator)); 
}
double Fraction::multiplication(Fraction& fraction2) 
{ 
	return (numerator / denominator * fraction2.numerator / fraction2.denominator); 
}
ostream& operator<<(ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;
	return out;
}
bool operator==(const Fraction& fraction1, const Fraction& fraction2) 
{ 
	return ((fraction1.numerator / fraction1.denominator) == (fraction2.numerator / fraction2.denominator)); 
}
int main()
{
	setlocale(0, "");
	Fraction Obj1(4, 2), Obj2(6, 3);
	cout << "Сумма дроби " << Obj1 << " и " << Obj2 << " : " << Obj1.sum(Obj2) << endl;
	cout << "Разность дроби " << Obj1 << " и " << Obj2 << " : " << Obj1.substract(Obj2) << endl;
	cout << "Произведение дроби " << Obj1 << " и " << Obj2 << " : " << Obj1.multiplication(Obj2) << endl;
	cout << "Деление дроби " << Obj1 << " и " << Obj2 << " : " << Obj1.division(Obj2) << endl;
	cout << "Сравнение дроби " << Obj1 << " и " << Obj2 << " : ";
	if (Obj1 == Obj2) cout << "Дроби равны" << endl; 
	else if (!Obj1.comparison(Obj2))cout << "Дробь " << Obj2 << " больше" << endl;
	else if (Obj1.comparison(Obj2)) cout << "Дробь " << Obj1 << " больше" << endl;
	setlocale(0, "");
	return 0;
}