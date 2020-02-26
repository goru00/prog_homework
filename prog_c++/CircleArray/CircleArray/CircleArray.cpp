
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

bool set(double* A, int N, bool flag, int tail, int& head, double a)
{
	if ((head == tail) && !flag) return false;

	A[head++] = a;
	if (head == N) head = 0;
	return true;
}

bool get(double* A, int N, bool flag, int& tail, int head, double& a)
{
	if (flag) return false;
	if (flag == false) {
		a = A[tail++];
		if (tail == N) tail = 0;
		if (tail == head) flag = true;
	}
	return flag;
}
bool show(double* A, int N, bool flag, int tail, int head) {
	if (flag)
		return false;
	do
	{
		cout << A[tail++] << '\t';
		if (tail == N) tail = 0;
	} while (head != tail);
	cout << "\n";
	return true;
}
int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 6;
	double number = 0;
	bool flag = false;
	int tail = 4, head = 2;
	double C[N] = {33, 44, -1, -1, 11, 22};
	show(C, N, flag, tail, head);
	get(C, N, flag, tail, head, number);
	cout << "Number:" << number << endl;
	set(C, N, flag, tail, head, 10);
	set(C, N, flag, tail, head, 12);
	set(C, N, flag, tail, head, 13);
	show(C, N, flag, tail, head);
	set(C, N, flag, tail, head, 18);
	show(C, N, flag, tail, head);
	/*set(C, N, flag, tail, head, 13);
	set(C, N, flag, tail, head, 15);
	set(C, N, flag, tail, head, 17);
	set(C, N, flag, tail, head, 18);
	show(C, N, flag, tail, head);*/
	system("pause");
}