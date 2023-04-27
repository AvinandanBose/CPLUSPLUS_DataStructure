#include <iostream>
using namespace std;

 struct Array
{
    int *a;
    int size;
};


struct Array array;

int main(){

    cout << "Enter the size of the array: " << endl;
    cin >> array.size;

    array.a = (int*) malloc(array.size * sizeof(int));

        for(int i = 0; i < array.size; i++){
            cout << "Enter the element: " << endl;
            cin >> array.a[i];
        }               


    cout << "The array is: " << endl;

        for(int i = 0; i < array.size; i++){
            cout << array.a[i] << endl;
        }

        free(array.a);
}





