#include<iostream>
using namespace std;

int check_prority(char c)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 3;
    }
    else if (x == '%')
    {
        return 4;
    }
    else if (x == '(' || x == ')')
    {
        return 0;
    }
    return -1;
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