#include <iostream>
using namespace std;

typedef struct Array
{
    int *a;
    int size;
    int pos;
} Arrays;

Arrays array;
Arrays *arr = &array;

int main()
{

    cout << "Enter the size of the array: " << endl;
    cin >> arr->size;
    arr->a = (int *)malloc(arr->size * sizeof(int));

    // Enter the elements of the array

    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < arr->size; i++)
    {
        cin >> arr->a[i];
    }

    cout << "Enter the position at which you want to delete the element: " << endl;

    cin >> arr->pos;

    for (int i = arr->pos - 1; i < arr->size - 1; i++)
    {
        arr->a[i] = arr->a[i + 1];
    }

    arr->size = arr->size - 1;

    arr->a = (int *)realloc(arr->a, arr->size * sizeof(int)); // reallocation

    cout << "The array after deletion is: " << endl;

    for (int i = 0; i < arr->size; i++)
    {
        cout << arr->a[i] << endl;
    }

    free(arr->a);
}