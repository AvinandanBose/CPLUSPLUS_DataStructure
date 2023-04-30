#include <iostream>
using namespace std;

typedef struct Array
{
    int ***a;
    int blocks;
    int row;
    int col;
} Arrays;

Arrays array;                       

Arrays *arr = &array;

int main()
{

    cout << "Enter the number of blocks: " << endl;
    cin >> arr->blocks;

    cout << "Enter the number of rows: " << endl;
    cin >> arr->row;

    cout << "Enter the number of columns: " << endl;
    cin >> arr->col;

    // Allocating memory for the blocks

    arr->a = (int ***)malloc(arr->blocks * sizeof(int **));

    // Allocating memory for the rows

    for (int i = 0; i < arr->blocks; i++)
    {
        arr->a[i] = (int **)malloc(arr->row * sizeof(int *));
    }

    // Allocating memory for the columns

    for (int i = 0; i < arr->blocks; i++)
    {
        for (int j = 0; j < arr->row; j++)
        {
            arr->a[i][j] = (int *)malloc(arr->col * sizeof(int));
        }
    }

    // Enter the elements of the array

    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < arr->blocks; i++)
    {
        for (int j = 0; j < arr->row; j++)
        {
            for (int k = 0; k < arr->col; k++)
            {
                cout << "arr[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr->a[i][j][k];
            }
        }
    }

    // Printing the array

    cout << "The array is: " << endl;

    for (int i = 0; i < arr->blocks; i++)
    {
        for (int j = 0; j < arr->row; j++)
        {
            for (int k = 0; k < arr->col; k++)
            {
                cout << arr->a[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    /****************************************************************/
    // Freeing the memory

    

    // Freeing the memory for the sub array of blocks

    for (int i = 0; i < arr->blocks; i++)
    {
        for (int j = 0; j < arr->row; j++)
        {
            free(arr->a[i][j]);
        }
    }

    // Freeing the memory for the sub array of rows

    for (int i = 0; i < arr->row; i++)
    {
        free(arr->a[i]);
    }

    // Free the array of pointers

    free(arr->a);

    /****************************************************************/
}


