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
    
    return 0;
}
