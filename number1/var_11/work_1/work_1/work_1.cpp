#include<iostream>
#include<string>
using namespace std;
class Polynom
{
private:
	double* koef;
	int n;
public:
	Polynom()
	{
		koef = NULL;
		n = -1;
	}
	Polynom(int a) : n(a)
	{
		koef = new double[n + 1];
		for (int i = 0; i <= n; i++) koef[i] = 0;
	}
	Polynom(const Polynom& p) : n(p.n)
	{
		koef = new double[n + 1];
		for (int i = 0; i <= n; i++) koef[i] = p.koef[i];
	}
	~Polynom() { delete[] koef; }
	double& operator[](int);
	bool trash();
	void rw_koef(int, double);
	bool operator==(const Polynom&);
	Polynom operator=(const Polynom&);
	Polynom operator+(const Polynom&);
	Polynom operator-(const Polynom&);
	Polynom operator*(const Polynom&);
	Polynom operator/(const Polynom&);
	Polynom operator%(const Polynom&);
	friend ostream& operator<<(ostream&, const Polynom&);
	friend istream& operator>>(istream&, const Polynom&);
};
double& Polynom::operator[](int index)
{
	return koef[index];
}
bool Polynom::trash()
{
	for (int i = 0; i <= n; i++) {
		if (koef[i] != 0) return false;
	}
	return true;
}
void Polynom::rw_koef(int count, double copy_koef)
{
	if (n < count) {
		double* temp = new double[count + 1];
		for (int i = 0; i < count + 1; i++) temp[i] = 0;
		for (int i = 0; i < n + 1; i++) temp[i] = koef[i];
		delete[] koef;
		koef = temp;
		n = count;
	}
	koef[count] = copy_koef;
}
bool Polynom::operator==(const Polynom& p)
{
	if (n != p.n) return false;
	for (int i = 0; i <= n; i++) {
		if (koef[i] != p.koef[i]) return false;
	}
	return true;
}
Polynom Polynom::operator=(const Polynom& p)
{
	if (this != &p) {
		delete[] koef;
		n = p.n;
		koef = new double[n + 1];
		for (int i = 0; i <= n; i++) koef[i] = p.koef[i];
	}
	return *this;
}
Polynom Polynom::operator+(const Polynom& p)
{
	if (n >= p.n) {
		Polynom temp = *this;
		for (int i = 0; i <= n; i++) {
			temp.koef[i] = koef[i] + p.koef[i];
		}
		return temp;
	} else {
		Polynom temp = p;
		for (int i = 0; i <= n; i++) {
			temp.koef[i] = p.koef[i] + koef[i];
		}
		return temp;
	}
}
Polynom Polynom::operator-(const Polynom& p)
{
	if (n >= p.n) {
		Polynom temp(*this);
		for (int i = 0; i <= p.n; i++) {
			temp.koef[i] = koef[i] - p.koef[i];
		}
		return temp;
	} else {
		Polynom temp(p.n);
		temp.n = p.n;
		for (int i = 0; i <= n; i++) temp.koef[i] = -p.koef[i] + koef[i];
		for (int i = n + 1; i <= p.n; i++) {
			temp.koef[i] = -p.koef[i];
		}
		return temp;
	}
}
Polynom Polynom::operator*(const Polynom& p)
{
	Polynom temp(n + p.n);
	temp.n = n + p.n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= p.n; j++) {
			temp.koef[i + j] += koef[i] * p.koef[j];
			//temp.delZero();
		}
	}
	return temp;
}
Polynom Polynom::operator/(const Polynom& p)
{
	Polynom result = 0, temp(*this);
	double koef_copy = 0;
	int count = 0;
	while (!temp.trash() && (temp.n >= p.n))
	{
		koef_copy = temp.koef[temp.n] / p.koef[p.n];
		count = temp.n - p.n;
		Polynom g;
		g.rw_koef(count, koef_copy);
		result = result + g;
		g = g * p;
		temp = temp - g;
	}
	return result;
}
Polynom Polynom::operator%(const Polynom& p)
{
	Polynom result = 0;
	Polynom temp(*this);
	double koef_copy = 0;
	int count = 0;
	while (!temp.trash() && (temp.n >= p.n))
	{
		koef_copy = temp.koef[temp.n] / p.koef[p.n];
		count = temp.n - p.n;
		Polynom g;
		g.rw_koef(count, koef_copy);
		g = g * p;
		temp = temp - g;
	}
	return temp;
}
/* вывод может работать неккоректно. например, вместо 1 выводить пустоту */
/* в след.версии понерфлю, тк для портфолио мне это важно */
ostream& operator<<(ostream& out, const Polynom& p)
{
	int n = 0;
	string koef_x;
	for (int i = 0; i <= p.n; i++) if (p.koef[i] != 0) n++;
	if (p.n >= 2) koef_x = "x^" + to_string(p.n);
	else if (p.n == 1) koef_x = "x";
	else koef_x = "";
	if (n != 0) {
		if (p.koef[0] == 1) out << koef_x;
		else if (p.koef[0] == 0) out << "";
		else out << p.koef[0] << koef_x;
		for (int i = 1, k = p.n - 1; i <= p.n; i++, k--) {
			if (k >= 2) koef_x = "x^" + to_string(k);
			else if (k == 1) koef_x = "x";
			else koef_x = "";
			if (i == p.n && p.koef[i] == 1) koef_x = "1";
			if (p.koef[i] != 0) {
				if (p.koef[i] < 0) {
					if (p.koef[i - 1] != 0) {
						if (p.koef[i] != -1) out << p.koef[i] << koef_x;
						else out << "-" << koef_x;
					}
					else {
						if (p.koef[i] != -1) out << p.koef[i] << koef_x;
						else out << "-" << koef_x;
					}
				}
				else {
					if (p.koef[i - 1] != 0) {
						if (p.koef[i] != 1) out << "+" << p.koef[i] << koef_x;
						else out << "+" << koef_x;
					}
					else {
						if (p.koef[i] != 1) out << p.koef[i] << koef_x;
						else out << koef_x;
					}
				}
			}
		}
		out << endl;
	} else out << 0;
	return out;
}
istream& operator>>(istream& in, const Polynom& p)
{
	for (int i = 0; i <= p.n; i++) in >> p.koef[i];
	return in;
}
int main()
{
	setlocale(0, "");
	int n, m;
	cout << "Введите степень первого многочлена: "; cin >> n;
	cout << "Введите степень второго многочлена: "; cin >> m;
	Polynom P_1(n), P_2(m), substract, sum, div, mod, mul;
	cout << "Введите члены первого многочлена: "; cin >> P_1;
	cout << "Введите члены второго многочлена: "; cin >> P_2;
	cout << "Первый многочлен: " << P_1 << endl;
	cout << "Второй многочлен: " << P_2 << endl;
	cout << "Разность многочленов: " << (substract = P_1 - P_2) << endl;
	cout << "Сумма многочленов: " << (sum = P_1 + P_2) << endl;
	cout << "Произведение многочленов: " << (mul = P_1 * P_2) << endl;
	cout << "Остаток от деления многочленов: " << (mod = P_1 % P_2) << endl;
	cout << "Частное от деления многочленов: " << (div = P_1 / P_2) << endl;
	cout << "Сравнение двух многочленов: ";
	if (P_1 == P_2) cout << "Многочлены равны!" << endl;
	else cout << "Многочлены не равны!" << endl;
	return 0;
}