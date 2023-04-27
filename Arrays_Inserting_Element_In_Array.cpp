#include <iostream>
using namespace std;

class Array
{
    private:
        int *a;
        int size;
    public:
        Array(int *a , int size) 
        {
            this->a = a;
            this->size = size;


            // Inserting an element in an array

           cout << "Enter the element we want to insert: " << endl;                 

            for (int i = 0; i < size; i++)
            {
                cin >> a[i];
            }    

            cout << "The array after insertion is: " << endl;                   
            
            
            // Array Traversal
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << endl;
            }
        }

};

int main()
{

    int size = 5;
    int myarr[size] ;
    Array arr(myarr,size);

    return 0;
}

        