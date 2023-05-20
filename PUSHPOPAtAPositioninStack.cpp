#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Stack
{
    int top;
    int size;
    int *s;
} Stack;

void create(Stack *st, int cap)
{
    st->size = cap;
    st->top = -1;
    st->s = new int[st->size];
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

// Push
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

// Insertion At A Position In Stack
void pushAtPos(Stack *st, int pos, int x)
{
    if (isFull(*st))
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    if (pos < 0 || pos > st->top + 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    for (int i = st->top; i > pos; i--)
    {
        st->s[i] = st->s[i - 1];
    }
    st->s[pos] = x;
    st->top++;
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

int popAtPos(Stack *st, int pos)
{

    if (isEmpty(*st))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    if (pos < 0 || pos > st->top)
    {

        return pos;
    }

    int x = st->s[pos];
    for (int i = pos; i < st->top; i++)
    {
        st->s[i] = st->s[i + 1];
    }
    st->top--;
    return x;
}

void stackTraversal(Stack st)
{
    if (isEmpty(st))
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        for (int i = st.top; i >= 0; i--)
        {
            cout << st.s[i] << " ";
        }
        cout << endl;
    }
}

int peek(Stack st)
{
    if (isEmpty(st))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return st.s[st.top];
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
        cout << "3. Push At A Position" << endl;
        cout << "4. Pop" << endl;
        cout << "5. Pop From A Position" << endl;
        cout << "6. Display" << endl;
        cout << "7. isEmpty" << endl;
        cout << "8. isFull" << endl;
        cout << "9. Peek" << endl;
        cout << "10. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int cap;
            cout << "Enter the size of the stack" << endl;
            cin >> cap;
            create(&stck, cap);
            cout << "Stack Created" << endl;
            break;
        case 2:
            int x;
            cout << "Enter the element you want to push" << endl;
            cin >> x;
            push(&stck, x);
            break;
        case 3:
            int pos;
            cout << "Enter the position at which you want to push" << endl;
            cin >> pos;
            cout << "Enter the element you want to push" << endl;
            cin >> x;
            pushAtPos(&stck, pos, x);
            break;
        case 4:
            if (!isEmpty(stck))
            {
                cout << "Popped element is " << pop(&stck) << endl;
            }
            else
            {
                cout << "Stack Underflow" << endl;
            }
            break;
        case 5:
            cout << "Enter the position from which you want to pop" << endl;
            cin >> pos;
            if (isEmpty(stck))
            {
                cout << "Stack Underflow" << endl;
            }
            else if (pos < 0 || pos > stck.top)
            {
                cout << popAtPos(&stck, pos) << ":Invalid Position" << endl;
            }
            else
            {
                cout << "Popped element is " << popAtPos(&stck, pos) << endl;
            }
            break;
        case 6:
            cout << "The elements in the stack are: " << endl;
            stackTraversal(stck);
            break;
        case 7:
            if (isEmpty(stck))
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is not Empty" << endl;
            }
            break;
        case 8:
            if (isFull(stck))
            {
                cout << "Stack is Full" << endl;
            }
            else
            {
                cout << "Stack is not Full" << endl;
            }
            break;
        case 9:
            cout << "The element at the top is " << peek(stck) << endl;
            break;
        case 10:
            free(stck.s);
            cout << "Exiting...." << endl;

            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
    return 0;
}
