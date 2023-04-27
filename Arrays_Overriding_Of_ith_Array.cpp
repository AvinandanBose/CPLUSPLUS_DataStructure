// write an dynamic array with new keyword with class
#include <iostream>
using namespace std;

class Array
{

private:
    int *a;
    int size;

public:
    Array(int *a, int size)
    {
        this->a = a;
        this->size = size;

        // Overriding of 3rd element
        a[2] = 5;

        // Array Traversal
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << endl;
        }
    }
};

int main()
{

    int myarr[] = {1, 2, 3, 4, 5};
    Array arr(myarr, 5);

    return 0;
}