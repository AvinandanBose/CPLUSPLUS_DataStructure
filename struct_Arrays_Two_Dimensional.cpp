#include <iostream>
using namespace std;

typedef struct Array
{
    int **a;
    int row;
    int col;
} Arrays;   

Arrays array;

Arrays *arr = &array;

int main()
{

    cout << "Enter the number of rows: " << endl;
    cin >> arr->row;

    cout << "Enter the number of columns: " << endl;
    cin >> arr->col;


    // Allocating memory for the rows
    arr->a = (int **)malloc(arr->row * sizeof(int *));

    // Allocating memory for the columns

    for (int i = 0; i < arr->row; i++)
    {
        arr->a[i] = (int *)malloc(arr->col * sizeof(int));
    }

// Enter the elements of the array
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < arr->row; i++)
    {
        for (int j = 0; j < arr->col; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";                     
            cin >> arr->a[i][j];
        }
    }

    // Printing the array

    cout << "The array is: " << endl;

    for (int i = 0; i < arr->row; i++)
    {
        for (int j = 0; j < arr->col; j++)
        {
            cout << arr->a[i][j] << " ";
        }
        cout << endl;
    }

/****************************************************************/
// Freeing the memory

// Freeing the subarray for the rows
    for (int i = 0; i < arr->row; i++)
    {
        free(arr->a[i]);
    }

// Freeing the array of pointers
    free(arr->a);

/****************************************************************/
}
