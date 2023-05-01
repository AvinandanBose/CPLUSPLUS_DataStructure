#include<iostream>
using namespace std;

int main(int num_args, char **arg_strings)
{
   int arr[10]={1,2,3,4,5,6,7,8,9,10};

    cout<<"The array is: "<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}