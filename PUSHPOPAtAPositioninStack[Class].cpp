#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack
{
public:
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

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            s[top] = x;
        }
    }

    void pushAtAGivenPosition(int x, int pos)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }

        else if (pos > top + 1 || pos < 0)
        {
            cout << "Invalid Position" << endl;
        }
        else
        {
            for (int i = top; i >= pos; i--)
            {
                s[i + 1] = s[i];
            }
            s[pos] = x;
            top++;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return s[top--];
        }
    }

    int popAtAGivenPosition(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else if (pos > top || pos < 0)
        {
            
            return pos;
            
        }
        else
        {
            int x = s[pos];
            for (int i = pos; i < top; i++)
            {
                s[i] = s[i + 1];
            }
            top--;
            return x;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return s[top];
        }
    }

    void traverse()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << s[i] << " ";
            }
            cout << endl;
        }
    }

    ~Stack()
    {
        delete[] s;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stck(size);
    cout << "Stack Created" << endl;

    int choice;
    while (1)
    {
        cout << "1. Push" << endl;
        cout << "2. Push At A Given Position" << endl;
        cout << "3. Pop" << endl;
        cout << "4. Pop At A Given Position" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Traverse" << endl;
        cout << "7. IsFull" << endl;
        cout << "8. IsEmpty" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter the element to be pushed: ";
            cin >> x;
            stck.push(x);
            break;

        case 2:
            int pos;
            cout << "Enter the position: ";
            cin >> pos;
            cout << "Enter the element to be pushed: ";
            cin >> x;
            stck.pushAtAGivenPosition(x, pos);
            break;

        case 3:
            if (stck.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "The popped element is: " << stck.pop() << endl;
            }
            break;

        case 4:
            int pos1;
            cout << "Enter the position from which you want to pop" << endl;
            cin >> pos1;
            if (stck.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else if (pos1 < 0 || pos1 > stck.top)
            {
                cout << stck.popAtAGivenPosition(pos1) << ":Invalid Position" << endl;
            }
            else
            {
                cout << "Popped element is :" << stck.popAtAGivenPosition(pos1) << endl;
            }
            
            break;

        case 5:
            cout << "The peek element is: " << stck.peek() << endl;
            break;

        case 6:
            cout << "The elements in the stack are: ";
            stck.traverse();
            break;

        case 7:
            if (stck.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;

        case 8:
            if (stck.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;

        case 9:
            stck.~Stack();
            cout << "Exiting the program" << endl;
            exit(0);

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}
