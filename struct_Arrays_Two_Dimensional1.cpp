#include <iostream>
using namespace std;

typedef struct Array
{
    int *a;
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

    arr->a = (int *)malloc(arr->row * arr->col * sizeof(int));

    // Enter the elements of the array

    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < arr->row; i++)
    {
        for (int j = 0; j < arr->col; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr->a[i * arr->col + j];
        }
    }

    // Printing the array

    cout << "The array is: " << endl;

    for (int i = 0; i < arr->row; i++)
    {
        for (int j = 0; j < arr->col; j++)
        {
            cout << arr->a[i * arr->col + j] << " ";
        }
        cout << endl;
    }


    // Freeing the memory

    free(arr->a);

    return 0;

}

