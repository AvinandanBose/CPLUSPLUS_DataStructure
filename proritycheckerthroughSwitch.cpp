#include <iostream>
using namespace std;

int check_prority(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '%':
            return 4;
        case '(':
        case ')':
            return 0;
        default:
            return -1;
    }
}

int main()
{
    char c;
    cout<<"Enter the expression: ";
    cin>>c;
    int prority = check_prority(c);
    cout<<"Prority of "<<c<<" is "<<prority<<endl;

    
    return 0;
}