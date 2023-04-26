#include <iostream> 
using namespace std;

class Array
{
   

public:
    Array(int a[], int b)
    {
        // Array Traversal
        for (int i = 0; i < b; i++)
        {
            cout << a[i] << endl;
            }                             
        
    }

    ~Array()
    {
        cout << "Destructor called" << endl;

        
    }


};

int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    Array arr(a, 5);

    return 0;                                   
    
}
    
