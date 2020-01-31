#include<iostream>
#include<math.h>
#define PI 3.14159
using namespace std;
class Angle
{
private:
	int grad_angle, min_angle;
public:
	Angle(int m_grad_angle, int m_min_angle) : grad_angle(m_grad_angle), min_angle(m_min_angle) { }
	Angle() : grad_angle(0), min_angle(0) {} 
	~Angle() {}
	int get_grad_angle() { return grad_angle; }
	int get_min_angle() { return min_angle; }
	double getRad();
	void Roughs();
	Angle Range();
	Angle sum(int, int);
	Angle substract(int, int);
	double sinA();
	friend ostream& operator<< (ostream&, const Angle&);
	bool operator==(const Angle&);
	bool operator<(const Angle&);
};
double Angle::sinA() 
{ 
	return sin(this->getRad()); 
}
double Angle::getRad() 
{ 
	return (grad_angle + min_angle / 60) * PI / 180; 
}
void Angle::Roughs()
{
	min_angle += grad_angle * 60;
	grad_angle = min_angle / 60;
	min_angle = min_angle % 60;
}
Angle Angle::Range()
{
	if (min_angle < 0) {
		grad_angle--;
		min_angle += 60;
	}
	if (grad_angle > 0) grad_angle %= 360;
	else grad_angle %= 360 + 360;
	return *this;
}
Angle Angle::sum(int in_grad, int in_min)
{
	grad_angle += in_grad;
	min_angle += in_min;
	this->Roughs();
	return *this;
}
Angle Angle::substract(int in_grad, int in_min)
{
	grad_angle -= in_grad;
	min_angle -= in_min;
	this->Roughs();
	return *this;
}
bool Angle::operator<(const Angle& angle)
{
	return ((this->grad_angle + this->min_angle) * 60 < (angle.grad_angle + angle.min_angle) * 60);
}
bool Angle::operator==(const Angle& angle)
{
	return ((this->grad_angle + this->min_angle) * 60 == (angle.grad_angle + angle.min_angle) * 60);
}
ostream& operator<< (ostream& out, const Angle& angle)
{
	out << "(" << angle.grad_angle << " , " << angle.min_angle << ")";
	return out;
}
int main()
{
	setlocale(0, "");
	Angle obj1(135, 25);
	Angle obj2(136, 25);
	cout << "Переведем в радианы первый угол: " << obj1.getRad() << endl;
	cout << "Переведем в радианы второй угол: " << obj2.getRad() << endl;
	cout << "Приведем к диапазону 0-360 первый угол: " << obj1.Range() << " и второй: " << obj2.Range() << endl;
	cout << "Увеличим первый угол: " << obj1.sum(25, 27) << endl;
	cout << "Уменьшим второй угол: " << obj2.substract(25, 27) << endl;
	cout << "Синус первого угла: " << obj1.sinA() << endl;
	if (obj1 == obj2) cout << "Углы равны!\n";
	else if (obj1 < obj2) cout << "Второй угол больше первого!\n";
	else cout << "Первый угол больше второго!\n";
	return 0;
}