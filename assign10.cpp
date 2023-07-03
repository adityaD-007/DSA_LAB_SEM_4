//============================================================================
// Name        : 2116.cpp
// Author      : aditya darade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class heap
{
    int *arr;
    int size;

public:
    heap(int x = 15)
    {
        size = -1;
        arr = new int[x];
    }

    void insert(int x)
    {

        size++;
        arr[size] = x;

        int i = size;
        while (i > 0 && arr[i] > arr[(i - 1) / 2])
        {

            swap(arr[i], arr[(i - 1) / 2]);

            i = (i - 1) / 2;
        }
    }

    void display()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " , ";
        }
        cout << endl;
    }

    void heapify(int i, int s)
    {

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int large = i;

        if (l <= s && arr[large] < arr[l])
            large = l;

        if (r <= s && arr[large] < arr[r])
            large = r;

        if (large != i)
        {
            swap(arr[large], arr[i]);
            heapify(large, s);
        }
    }

    void sort()
    {
        int i = size;

        while (i != 0)
        {
            swap(arr[0], arr[i]);

            i--;
            heapify(0, i);
        }
    }

    void del()
    {

        swap(arr[0], arr[size]);

        size--;
        heapify(0, this->size);

        
    }
};

int main()
{

    cout << "Hello\n";
    heap h1(20);

    h1.insert(21);
    h1.insert(216);

    h1.insert(6);

    h1.insert(11);
    h1.insert(25);
    h1.insert(67);
    h1.insert(100);
    h1.insert(95);
    h1.insert(23);
    h1.insert(11);
    h1.insert(12);

    h1.display();

    h1.del();
    h1.display();
    h1.del();
    h1.display();
    h1.del();
    h1.display();
}