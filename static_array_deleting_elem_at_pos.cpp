#include <iostream>

using namespace std;

int main(int argc, char *argv[], char *envp[])

{
    //Inserting elements in a array

    int size ;
    cout << "Enter the size of the array: ";
    cin >> size;
    int a[size];

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];                            
    }

    cout << "The array is: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "]=" << a[i] << endl;
    }

    //Deleting elements in a array

    int pos;
    cout << "Enter the position at which you want to delete the element: ";
    cin >> pos; 

    for (int i = pos - 1; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }

    size = size - 1;

    cout << "The array after deletion is: " << endl;            

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "]=" << a[i] << endl;
    }                                                          
    
    return 0;
}