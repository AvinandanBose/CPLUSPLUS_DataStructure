#include <iostream>
using namespace std;

 struct Array
{
    int *a;
    int size;
} array , *arr=&array;


int main()
{

    arr->size = 5;
    arr->a = (int *)malloc(arr->size * sizeof(int));

    arr->a[0] = 1;
    arr->a[1] = 2;
    arr->a[2] = 3;
    arr->a[3] = 4;
    arr->a[4] = 5;

    cout << "The array is: " << endl;

    for (int i = 0; i < arr->size; i++)
    {
        cout << arr->a[i] << endl;
    }

    free(arr->a);
}

