//write an dynamic array with new keyword with class
#include <iostream>                 
using namespace std;

class Array
{

    int *a;
    int size;
public:
    Array(int b)
    {
        size = b;
        a = new int[size];
        //Array Traversal
        for (int i = 0; i < size; i++)
        {
            a[i] = i;
        }
    }

    ~Array()
    {
        delete[] a;
        cout << "Destructor called" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << endl;
        }
    }
};

int main()
{
    Array arr(5);
    arr.print();

    return 0;
}
