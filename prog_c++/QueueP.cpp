#include<iostream>
#include<cassert>
#include<string>
using namespace std;
template<class T>
class QueueP
{
private:
	T* mass;
	int* p;
	int size;
public:
	QueueP()
	{
		size = 0;
		p = NULL;
		mass = NULL;
	}
	~QueueP()
	{
		if (size > 0) {
			delete[] mass;
			delete[] p;
		}
	}
	void Push(T, int);
	void Pop();
	void Erase();
	void Show();
	bool Empty() { return size == 0; }
};
template<class T>
void QueueP<T>::Push(T arg, int index)
{
	T* m_mass = new T[size + 1];
	int* m_p = new int[size + 1];
	int pos;
	if (size == 0) pos = 0;
	else {
		pos = 0;
		while (pos < size)
		{
			if (p[pos] > index) break;
			pos++;
		}
	}
	for (int i = 0; i < pos; i++)
	{
		m_mass[i] = mass[i];
		m_p[i] = p[i];
	}
	m_mass[pos] = arg;
	m_p[pos] = index;
	for (int i = pos + 1; i < size + 1; i++)
	{
		m_mass[i] = mass[i - 1];
		m_p[i] = p[i - 1];
	}
	delete[] mass;
	delete[] p;
	mass = m_mass;
	p = m_p;
	size++;
}
template<class T>
void QueueP<T>::Pop()
{
	T* m_mass = new T[size - 1];
	int* m_p = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		m_mass[i] = mass[i + 1];
		m_p[i] = p[i + 1];
	}
	delete[] mass;
	delete[] p;
	mass = m_mass;
	p = m_p;
	size--;
}
template<class T>
void QueueP<T>::Show()
{
	for (int i = 0; i < size; i++) cout << mass[i] << endl;
}
template<class T>
void QueueP<T>::Erase()
{
	if (size > 0) {
		size = 0;
		delete[] mass;
		delete[] p;
	}
}
int main()
{
	setlocale(0, "");
	QueueP<int> queue;
	queue.Push(15, 2);
	queue.Push(2, 7);
	queue.Push(12, 5);
	queue.Push(4, 3);
	queue.Pop();
	queue.Show();
	queue.Erase();
	if (queue.Empty()) cout << "Очередь пуста" << endl;
	return 0;
}