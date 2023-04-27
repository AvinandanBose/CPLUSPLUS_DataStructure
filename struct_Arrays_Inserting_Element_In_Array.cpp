#include <iostream>
using namespace std;

typedef struct Array
{
    int *a;
    int size;
} Arrays;

Arrays array;
Arrays *arr = &array;

int main()
{

   cout<< "Enter the size of the array: "<<endl;
    cin>>arr->size;
    arr->a = (int *)malloc(arr->size * sizeof(int));

    //Enter the elements of the array

    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < arr->size; i++)
    {
        cin >> arr->a[i];
    }


    cout << "The array is: " << endl;

    for (int i = 0; i < arr->size; i++)
    {
        cout << arr->a[i] << endl;
    }


    free(arr->a);
}