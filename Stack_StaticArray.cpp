#include <iostream>
#include <stdlib.h>

using namespace std;

int top = -1; //Global variable
void push(int stack[], int item, int size)
{

    if (top == size - 1)
    {

        cout << "Stack Overflow" << endl;
        return;
    }

    top++;
    stack[top] = item;
}

void pop(int stack[])
{

    if (top == -1)
    {

        return;
    }
    cout << "Item popped" << stack[top] << endl;
    top--;
}

int peek(int stack[])
{

    if (top == -1)
    {

        return -1;
    }

    return stack[top];
}

void traverseStack(int stack[])
{

    if (top == -1)
    {

        cout << "Stack is empty" << endl;
    }

    for (int i = top; i >= 0; i--)
    {

        cout << stack[i] << " ";
    }
    cout << endl;
}

void isEmpty()
{

    if (top == -1)
    {

        cout << "Stack is empty" << endl;
    }
    else
    {

        cout << "Stack is not empty" << endl;
    }
}

void isFull(int size)
{

    if (top == size - 1)
    {

        cout << "Stack is full" << endl;
    }
    else
    {

        cout << "Stack is not full" << endl;
    }
}

int main()
{

    int size;
    cout << "Enter the size of the stack" << endl;
    cin >> size;
    int stack[size];
    cout << "Stack is Created" << endl;
    int choice;
    int item;
    while (1)
    {

        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. isFull" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter the item to be pushed" << endl;
            cin >> item;
            push(stack, item, size);
            break;

        case 2:
            if (top == -1)
            {

                cout << "Stack Overflow" << endl;
            }
            else
            {
                pop(stack);
            }
            break;

        case 3:
            cout << "Item at the top is " << peek(stack) << endl;
            break;

        case 4:
            traverseStack(stack);
            break;

        case 5:
            isEmpty();
            break;

        case 6:
            isFull(size);
            break;

        case 7:
            exit(0);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
