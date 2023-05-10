// Amortized Stack Operation

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
    if (st.top == st.size - 1)
    {
        return 1;
    }
    return 0;
}

void doubleStack(Stack *st)
{
    st->size = st->size * 2;
    st->s = (int *)realloc(st->s, st->size * sizeof(int));
}

void push(Stack *st, int x)
{

    if (isFull(*st))
    {
        doubleStack(st);
        st->top++;
        st->s[st->top] = x;
        return;
    }

    else{

        st->top++;
        st->s[st->top] = x;
    }

    
}

int pop(Stack *st)
{

    if (isEmpty(*st))
    {
        cout << "Stack Underflow" << endl;
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

int peek(Stack *st)
{
    if (!isEmpty(*st))
    {
        return st->s[st->top];
    }
    return -1;
}

void deleteStack(Stack *st)
{
    free(st->s);
    cout << "Stack deleted" << endl;
    cout << "Exiting..." << endl;
    exit(0);

}

int main()
{

    Stack st;
    int cap;
    cout << "Enter the capacity of the stack" << endl;

    cin >> cap;

    int choice;

    while (1)
    {
        cout << "1. Create" << endl;
        cout << "2. Push" << endl;
        cout << "3. Pop" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Traverse" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            create(&st, cap);
            cout << "Stack created" << endl;
            break;

        case 2:

            int elem;
            for (int i = 0; i < 2* cap; i++)
            {
                cout << "Enter the element to be pushed :" << endl;
                
                cin >> elem;
                push(&st, elem);
            }
            
            break;

        case 3:
            if (!isEmpty(st))
            {
                for (int i = 0; i < cap; i++)
                {
                    cout << "Popped element is: " << pop(&st) << endl;
                }
                
            }
            else
            {
                cout << "Stack Underflow" << endl;
                
            }

            break;

        case 4:
            cout << "Peeked element is " << peek(&st) << endl;
            break;

        case 5:
            stackTraversal(st);
            break;

        case 6:
            deleteStack(&st);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
