#include <iostream>
using namespace std;

class Array
{
private:
    int *a;
    int row;
    int col;

public:

    Array(int *a, int row, int col)
    {
        this->a = a;
        this->row = row;
        this->col = col;

        
        a = new int[row * col];
        // Inserting the element in an array

        cout << "Enter the elements we want to insert: " << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col;j++)
            {
                cout << " a[" << i << "][" << j << "]: ";
                cin >> *((a+i*col) + j);
            }
        }

        

        cout << "The array traversal of 2D array is: " << endl;

        // Array Traversal
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col;j++)
            {
                cout << " a[" << i << "][" << j << "]: ";
                cout << *((a + i * col) + j) << endl;
            }
        }
    }
};

int main()
{

    int row = 2;
    int col = 2;
    int myarr[row][col] ;
    
    Array arr((int*)myarr, row, col);

    return 0;
}

