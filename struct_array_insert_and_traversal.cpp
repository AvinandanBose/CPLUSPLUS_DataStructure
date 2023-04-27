#include <iostream>
using namespace std;

 struct Array
{
    int *a;
    int size;
};


struct Array array;

int main(){

   
array.size = 5;
array.a = (int *)malloc(array.size * sizeof(int));

array.a[0] = 1;
array.a[1] = 2;
array.a[2] = 3;
array.a[3] = 4;
array.a[4] = 5;

cout << "The array is: " << endl;

for (int i = 0; i < array.size; i++)
{
    cout << array.a[i] << endl;
        }

        free(array.a);
}





