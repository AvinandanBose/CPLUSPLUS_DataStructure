#include <iostream>
using namespace std;

int main(int argc, char *argv[], char *envp[])
{
    int block, row, col;

    cout << "Enter the number of blocks: ";
    cin >> block;

    cout << "Enter the number of rows: ";
    cin >> row;

    cout << "Enter the number of columns: ";                        
    cin >> col;

    int a[block][row][col];

    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < block; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                cout << "a[" << i << "][" << j << "][" << k << "] = ";
                cin >> a[i][j][k];
            }
        }
    }


    cout << "The array is: " << endl;


    for (int i = 0; i < block; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                cout << a[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}