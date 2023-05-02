#include <iostream>
using namespace std;

int main(int arg_count, char **arg_vector, char **env_pointer)
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};

    //Accessing the array elements(Array Traversal)

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Overriding the ith element of the array
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

//New array after overriding the ith element
    cout << "The array is: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;


}