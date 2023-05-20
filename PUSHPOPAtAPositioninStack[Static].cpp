#include <iostream>
#include <stdlib.h>

using namespace std;

int top = -1; // Global variable
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

void pushAtAGivenPos(int stack[], int item, int size, int pos)
{

    if (top == size - 1)
    {

        cout << "Stack Overflow" << endl;
        return;
    }
    else if (pos > top + 1 || pos < 0)
    {

        cout << pos <<":Invalid Position" << endl;
        return;
    }

    else
    {
        for (int i = top; i >= pos; i--)
        {

            stack[i + 1] = stack[i];
        }
        stack[pos] = item;

        top++;
    }
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

void popAtGivenPos(int stack[], int pos)
{

    if (top == -1)
    {

        cout << "Stack Underflow" << endl;
        return;
    }

    else if (pos > top || pos < 0)
    {

        cout << pos << ":Invalid Position" << endl;
        return;
    }
    else
    {
        cout << "Item popped: " << stack[pos] << endl;
        for (int i = pos ; i < top; i++)
        {

            stack[i] = stack[i + 1];
        }
        top--;
    }
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
        cout << "2. PushAtAGivenPos" << endl;
        cout << "3. Pop" << endl;
        cout << "4. PopAtGivenPos" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Traverse" << endl;
        cout << "7. isEmpty" << endl;
        cout << "8. isFull" << endl;
        cout << "9. Exit" << endl;
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
            cout << "Enter the item to be pushed" << endl;
            cin >> item;
            int pos;
            cout << "Enter the position" << endl;
            cin >> pos;
            pushAtAGivenPos(stack, item, size, pos);
            break;

        case 3:
            if (top == -1)
            {

                cout << "Stack Overflow!!!" << endl;
            }
            else
            {
                pop(stack);
            }
            break;

        case 4:

            if (top == -1)
            {

                cout << "Stack Underflow!!!" << endl;
            }
            else
            {
                int pos;
                cout << "Enter the position" << endl;
                cin >> pos;
                popAtGivenPos(stack, pos);
            }
            break;

        case 5:
            cout << "Item at the top is " << peek(stack) << endl;
            break;

        case 6:
            traverseStack(stack);
            break;

        case 7:
            isEmpty();
            break;

        case 8:
            isFull(size);
            break;

        case 9:
            exit(0);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}