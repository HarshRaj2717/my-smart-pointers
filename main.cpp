/**
 * @file main.cpp
 * @brief My simple implementation of smart pointers in cpp
 * @author Harsh Raj
 * @date 2024-09-19
 */

#include <bits/stdc++.h>

using namespace std;

class MySharedPtr
{
    int *refCount;
    int *rawPointer;

public:
    MySharedPtr(int *pointer) : refCount{new int(1)}, rawPointer{pointer}
    {
        cout << "construct A" << endl;
    }

    MySharedPtr(int *pointer, int *refCount) : refCount{refCount}, rawPointer{pointer}
    {
        cout << "construct B" << endl;
    }

    MySharedPtr copier()
    {
        (*refCount)++;
        return MySharedPtr(rawPointer, refCount);
    }

    ~MySharedPtr()
    {
        (*refCount)--;
        if (*refCount == 0)
        {
            delete refCount;
            delete rawPointer;
            cout << "Destuct" << endl;
        }
    }
};

int main()
{
    shared_ptr<int> x;
    MySharedPtr a(new int(100));
    MySharedPtr c(new int(200));

    {
        MySharedPtr b = a.copier();
        MySharedPtr d(new int(300));
    }

    return 0;
}