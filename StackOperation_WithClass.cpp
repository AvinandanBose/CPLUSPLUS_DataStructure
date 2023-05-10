#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *s;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        s = new int[size];
    }

  

    int isEmpty(Stack st)
    {
        if (st.top == -1)
        {
            return 1;
        }
        return 0;
    }

    int isFull(Stack st)
    {
        if (st.top == st.size - 1)
        {
            return 1;
        }
        return 0;
    }

    void push(int x, Stack st)
    {
        if (isFull(st))
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            s[top] = x;
        }
    }

    int pop(Stack st)
    {

        if (isEmpty(st))
        {
            cout << "Stack Underflow" << endl;
        }

        return s[top--];
    }

    int peek(Stack st)
    {
        if (isEmpty(st))
        {
            return -1;
        }
        return s[top];
    }

    void traverse()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] s;
       
    }
};

int main()
{

    int size;
    cout << "Enter the size of the stack" << endl;
    cin >> size;
    Stack stck(size);
    cout << "Stack Created" << endl;
    int choice;

    while (1)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3.Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5.IsFull" << endl;
        cout << "6.IsEmpty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter the element to be pushed" << endl;
            cin >> x;
            stck.push(x, stck);
            break;

        case 2:

            if (stck.isEmpty(stck))
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "The popped element is " << stck.pop(stck) << endl;
            }

            break;

        case 3:
            cout <<"The peek element is " << stck.peek(stck) << endl;
            break;

        case 4:
            stck.traverse();
            break;

        case 5:
            if (stck.isFull(stck))
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;

        case 6:
            if (stck.isEmpty(stck))
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;

        case 7:
             stck.~Stack();
            cout << "Exiting the program" << endl;
            exit(0);

            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}
