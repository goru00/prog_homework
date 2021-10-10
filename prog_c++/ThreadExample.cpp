#include <iostream>
#include <thread>

using namespace std;

class A
{
public:
    void operator()(int a[], int len)
    {
        for (int i = 0; i < len; i++)
        {
            a[i] *= 2;
        }
    }
    void B(int a[], int len)
    {
        for (int i = 0; i < len; i++)
        {
            a[i] *= -1;
        }
    }
};
int main() {
    const int length = 5;
    int a[length] = { 1, 2, 3, 4, 5 };
    A obj;
    thread a_thread(obj, a, length);
    thread k_thread(&A::B, &obj, a, length);
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << "\t";
    }
    a_thread.join();
    k_thread.join();
    return 0;
}
