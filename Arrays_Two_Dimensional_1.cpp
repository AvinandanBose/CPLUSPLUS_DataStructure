#include <iostream>
using namespace std;

class Array
{
private:
    int **a;
    int row;
    int col;
    

public:

    Array(int **a, int row, int col)
    {
        this->a = a;
        this->row = row;
        this->col = col;
       
        // Allocating memory for the rows

        a = (int **)malloc(row * sizeof(int *));

        // Allocating memory for the columns
        for (int i = 0; i < row; i++)
        {
            a[i] = (int *)malloc(col * sizeof(int));
        }

        // Enter the elements of the array

        cout << "Enter the elements of the array: " << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                cout << "a[" << i << "][" << j << "] = ";
                cin >> *(*(a + i) + j);                 
            }
        }

        // Printing the array

        cout << "The array is: " << endl;


        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                cout << "a[" << i << "][" << j << "] = ";
                cout << *(*(a + i) + j) << " ,";
            }
            cout << endl;


    }


    }


    ~Array()
    {

    cout << "Array deleted" << endl;
    cout << "Destructor is called!" << endl;

    // Deallocating the memory
    
    // Free each sub-array (row)
    for (int i = 0; i < row; i++)
    {
            delete[] a[i];
     }
        
        //Free the array of pointers
        delete[] a;
        
    }
};

int main()
{

    int row = 2;
    int col = 2;
    int myarr[row][col] ;
    
    Array arr((int**)myarr, row, col);

    

    return 0;
}

