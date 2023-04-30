#include <iostream>
using namespace std;

class Array
{

private:
    int ***a;
    int row;
    int col;
    int page;

public:

    Array(int ***a, int page, int row, int col)
    {

        this->a = a;
        this->row = row;
        this->col = col;
        this->page = page;

        // Allocating memory for the pages
        a = (int ***)malloc(page * sizeof(int **));

        // Allocating memory for the rows
        for (int i = 0; i < page; i++)
        {
            a[i] = (int **)malloc(row * sizeof(int *));
        }

        // Allocating memory for the columns
        for (int i = 0; i < page; i++)
        {
            for (int j = 0; j < row; j++)
            {
                a[i][j] = (int *)malloc(col * sizeof(int));
            }
        }

        // Enter the elements of the array

        cout << "Enter the elements of the array: " << endl;

        for (int i = 0; i < page; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    cout << "a[" << i << "][" << j << "][" << k << "] = ";
                    cin >> *(*(*(a + i) + j) + k);
                }
            }
        }

        // Printing the array

        cout << "The array is: " << endl;

        for (int i = 0; i < page; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    cout << "a[" << i << "][" << j << "][" << k << "] = ";
                    cout << *(*(*(a + i) + j) + k) << " ,";
                }
                cout << endl;
            }
            cout << endl;
        }                           
       
    }

    ~Array()
    {

        cout << "Array deleted" << endl;
        cout << "Destructor is called!" << endl;


        // Deallocating memory 
        
        //Free each sub-array for the pages
        for (int i = 0; i < page; i++)
        {
            for (int j = 0; j < row; j++)
            {
                delete[] a[i][j];
            }
        }

        // Free each sub-array for the row
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

    int page = 2;
    int row = 2;
    int col = 2;
    int myarr[page][row][col];

    Array arr((int***)myarr, page, row, col);

    return 0;
}
