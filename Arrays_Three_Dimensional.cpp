#include <iostream>
using namespace std;

class Array
{

private:
    int *a;
    int row;
    int col;
    int page;

public:

    Array(int *a, int page, int row, int col)
    {
        this->a = a;
        this->row = row;
        this->col = col;
        this->page = page;

        
        a = new int[page * row * col];
        // Inserting the element in an array

        cout << "Enter the elements we want to insert in 3D array: " << endl;

        for (int i = 0; i < page; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    cout << " a[" << i << "][" << j << "][" << k << "]: ";
                    cin >> *((a + i * row * col) + j * col + k);
                }
            }
        }

        

        cout << "The array traversal of 3D array is: " << endl;

        // Array Traversal
        for (int i = 0; i < page; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    cout << " a[" << i << "][" << j << "][" << k << "]: ";
                    cout << *((a + i * row * col) + j * col + k) << endl;
                }
            }
        }
    }
    
     ~Array()
    {
        delete[] a;
        cout << "Array deleted" << endl;
        cout << "Destructor is called!" << endl;
    }
};


int main()
{

    int page = 2;
    int row = 2;
    int col = 2;
    int myarr[page][row][col];

    Array arr((int*)myarr, page, row, col);

    return 0;
}
