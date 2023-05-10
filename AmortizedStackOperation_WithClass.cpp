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
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }

    void push(int x)
    {
        if (isFull())
        {
            size = 2* size;
            int *new_s = new int[size];
            for (int i = 0; i <= top; i++)
            {
                new_s[i] = s[i];
            }
            delete[] s;
            s = new_s;
        }
        ++top;
        s[top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int x = s[top];
        --top;
        return x;
    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        else{
            return s[top];
        }
    }

   

    void traverse()
    {
        for (int i = top; i >=0; i--)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] s;
        cout << "Stack Deleted" << endl;
    }
};

int main()
{
    int cap;
    cout << "Enter the size of the stack" << endl;
    cin >> cap;
    Stack stck(cap);

    int choice;
    while (true)
    {

        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Peek" << endl;
        cout << "5. IsFull" << endl;
        cout << "6. IsEmpty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            int elem;
            for (int i = 0; i < 2 * cap; i++)
            {
                cout << "Enter the element to be pushed :" << endl;
                cin >> elem;
                stck.push(elem);
            }
            break;

        case 2:
            if (stck.isEmpty())
            {
                cout << "Stack UnderFlow" << endl;
            }
            else
            {
                for (int i = 0; i < cap; i++)
                {
                    cout << "The popped element is " << stck.pop() << endl;
                }
            }
            break;

        case 3:
            stck.traverse();
            break;

        case 4:
           cout<<"The peek element is " << stck.peek() << endl;
           
           break;

        case 5:
            if (stck.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;

        case 6:
            if (stck.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;

        case 7:
            cout << "Exiting the program" << endl;
            exit(0);

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}
