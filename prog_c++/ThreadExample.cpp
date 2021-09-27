#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
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
            a[i] = 9;
        }
    }
};
int main() {
    const int length = 5;
    int a[length] = { 1, 2, 3, 4, 5 };
    A obj;
    thread a_thread(obj, a, length);
    thread k_thread(&A::B, &obj, a, length);
    if (a_thread.joinable() )
    {
        a_thread.join();
    }
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << "\t";
    }
    return 0;
}
