// Creation of Stack

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Stack
{
    int top;
    int size;
    int *s;

} Stack;

void create(Stack *st)
{
    cout << "Enter the size of the stack" << endl;
    cin >> st->size;
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
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
    return st.top == st.size - 1;
}

void push(Stack *st, int x)
{
    if (isFull(*st))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st)
{

    if (isEmpty(*st))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    return st->s[st->top--];
}

void stackTraversal(Stack st)
{

    if (isEmpty(st))
    {
        cout << "Stack is Empty" << endl;
    }

    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

int peek(Stack st)
{
    if (!isEmpty(st))
    {
        return st.s[st.top];
    }
    return -1;
}

int main()
{

    Stack stck;
    int choice;

    while (1)
    {

        cout << "Enter the operation you want to perform" << endl;
        cout << "1. Create Stack" << endl;
        cout << "2. Push" << endl;
        cout << "3. Pop" << endl;
        cout << "4. Display" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. isFull" << endl;
        cout << "7. Peek" << endl;
        cout << "8. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:

            create(&stck);
            cout << "Stack Created" << endl;
            break;

        case 2:

            int x;
            cout << "Enter the element you want to push" << endl;
            cin >> x;
            push(&stck, x);
            break;

        case 3:

            if (!isEmpty(stck))
            {
                cout << "Popped element is " << pop(&stck) << endl;
            }
            else
            {
                cout << "Stack Underflow" << endl;
            }
            break;

        case 4:
            cout << "The elements in the stack are: " << endl;
            stackTraversal(stck);
            break;

        case 5:

            if (isEmpty(stck))
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is not Empty" << endl;
            }
            break;

        case 6:

            if (isFull(stck))
            {
                cout << isFull(stck) << endl;
                cout << "Stack is Full" << endl;
            }
            else
            {
                cout << "Stack is not Full" << endl;
            }
            break;

        case 7:

            cout << "The element at the top is " << peek(stck) << endl;
            break;

        case 8:
            cout << "Exiting...." << endl;
            free(stck.s);
            stck.s = NULL;
            exit(0);
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}



