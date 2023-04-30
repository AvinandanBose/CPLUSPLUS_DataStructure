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

            int pos;
            cout << "Enter the position where you want to insert the element: " << endl;
            cin >> pos;

            int element;
            cout << "Enter the element you want to insert: " << endl;
            cin >> element;

            size = size + 1;                

            for (int i = size-1; i > pos; i--)
            {
                a[i] = a[i-1];
            }

            a[pos] = element;

            cout << "The array after insertion is: " << endl;

            // Array Traversal
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << endl;
            }
        }
        
         ~Array(){

            delete [] a;

            cout<<"Array deleted"<<endl;
            cout<<"Destructor is called!" << endl;
        }
};

int main()
{

    int size = 5;
    int myarr[size] ;
    Array arr(myarr,size);

    return 0;
}
            

            
