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

        // Inserting an element in an array

        cout << "Enter the element we want to insert: " << endl;

        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }

        int pos;
        cout << "Enter the position where you want to delete the element: " << endl;
        cin >> pos;

       

        cout << "Delete the element from array at a position: " << endl;

        for (int i = pos - 1; i < size-1; i++)
        {
            a[i] = a[i + 1];
        }

        size = size - 1;

        cout << "The array after deletion is: " << endl;

        // Array Traversal
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << endl;
        }
    }
};

int main()
{

    int size = 5;
    int myarr[size];
    Array arr(myarr, size);

    return 0;
}
