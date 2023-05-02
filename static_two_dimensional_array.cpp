#include<iostream>
using namespace std;

int main(int argc, char *argv[], char *envp[])
{
    int row, col;

    cout << "Enter the number of rows: ";
    cin >> row;

    cout << "Enter the number of columns: ";
    cin >> col;

    int a[row][col];

    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) 
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }        

    cout << "The array is: " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) 
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
                       

    return 0;
}