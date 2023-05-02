#include<iostream>
using namespace std;

int main(int argc, char *argv[], char *envp[])
{
    int size;
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

    int pos, elem;
    cout << "Enter the position at which you want to insert the element: ";
    cin >> pos;
    cout << "Enter the element you want to insert: ";
    cin >> elem;

    size = size + 1;

    for (int i = size - 1; i > pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos] = elem;
    

    cout << "The array after inserting the element is: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "]=" << a[i] << endl;
    }

    return 0;
}