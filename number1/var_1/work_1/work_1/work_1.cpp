#include<iostream>
#include<math.h>
using namespace std;
class Angle
{
private:
	double grad_angle, min_angle;
public:
	Angle(double m_grad_angle, double m_min_angle)
	{
		grad_angle = m_grad_angle;
		min_angle = m_min_angle;
	}
	Angle() {} // настоящие мужики в любой ситуации создают конструктор по умолчанию
	~Angle() {}
	void rad()
	{
		grad_angle = grad_angle * 3.14159 / 180;
		min_angle = min_angle * 3.14159 / (60 * 180);
	}
	void sum(double value)
	{
		grad_angle += value;
		min_angle += value;
	}
	void substract(double value)
	{
		grad_angle -= value;
		min_angle -= value;
	}
	void sinx() { sin(grad_angle); sin(min_angle); }
	friend bool operator==(const Angle &angle1, const Angle &angle2);
	friend bool operator<(const Angle& angle1, const Angle& angle2);
	friend bool operator>(const Angle& angle1, const Angle& angle2);
	friend ostream& operator<< (ostream& out, const Angle& angle);
};
bool operator==(const Angle &angle1, const Angle &angle2)
{
	return (angle1.grad_angle == angle2.grad_angle);
}
bool operator<(const Angle &angle1, const Angle &angle2)
{
	return (angle1.grad_angle < angle2.grad_angle);
}
bool operator>(const Angle &angle1, const Angle &angle2)
{
	return (angle1.grad_angle > angle2.grad_angle);
}
ostream& operator<< (ostream& out, const Angle& angle)
{
	out << angle.grad_angle << "\t" << angle.min_angle << endl;
	return out;
}
int main()
{
	setlocale(0, "");
	Angle obj1(135.5, 25);
	Angle obj2(13, 23);
	obj1.rad(); cout << "Переведем в радианы первый угол: " << obj1;
	obj2.rad(); cout << "Переведем в радианы второй угол: " << obj2; // сравнивать в радианах два объекта как по мне намного легче :)

	if (obj1 == obj2) cout << "Оба угла равны";
	else if (obj1 > obj2) cout << "Первый угол больше второго\n";
	else if (obj1 < obj2) cout << "Второй угол больше первого\n";

	obj1.sum(156.5); cout << "Увеличение: " << obj1;
	obj1.substract(123.7); cout << "Уменьшение: " << obj1;
	obj1.sinx(); cout << "Преобразование в синус: " << obj1;
	return 0;
}