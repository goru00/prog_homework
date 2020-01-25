#include<iostream>
using namespace std;
class Fraction
{
private:
	int denominator, numerator;
public:
	Fraction(int m_numerator, int m_denominator) : numerator(m_numerator), denominator(m_denominator) { }
	~Fraction() {}
	double sum(Fraction &fraction2) { return (numerator / denominator + fraction2.numerator / fraction2.denominator); }
	double substract(Fraction& fraction2) { return (numerator / denominator - fraction2.numerator / fraction2.denominator); }
	double multiplication(Fraction& fraction2) { return (numerator / denominator * fraction2.numerator / fraction2.denominator); }
	double division(Fraction& fraction2) { return ((numerator / denominator) / (fraction2.numerator / fraction2.denominator)); }
	bool comparison(Fraction& fraction2) { if ((numerator / denominator) > (fraction2.numerator / fraction2.denominator)) return true; }
	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	// написал просто для проверки равенства. но можно было все в метод один запихнуть, но я бака!
	friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);
};
ostream& operator<<(ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;
	return out;
}
bool operator==(const Fraction& fraction1, const Fraction& fraction2) { return ((fraction1.numerator / fraction1.denominator) == (fraction2.numerator / fraction2.denominator)); }
int main()
{
	setlocale(0, "");
	Fraction obj1(4, 2);
	Fraction obj2(6, 3);
	cout << "Сумма дроби " << obj1 << " и " << obj2 << " : " << obj1.sum(obj2) << endl;
	cout << "Разность дроби " << obj1 << " и " << obj2 << " : " << obj1.substract(obj2) << endl;
	cout << "Произведение дроби " << obj1 << " и " << obj2 << " : " << obj1.multiplication(obj2) << endl;
	cout << "Деление дроби " << obj1 << " и " << obj2 << " : " << obj1.division(obj2) << endl;
	cout << "Сравнение дроби " << obj1 << " и " << obj2 << " : ";
	if (obj1 == obj2) cout << "Дроби равны" << endl; 
	else if (!obj1.comparison(obj2))cout << "Дробь " << obj2 << " больше" << endl;
	else if (obj1.comparison(obj2)) cout << "Дробь " << obj1 << " больше" << endl;
	setlocale(0, "");
	return 0;
}