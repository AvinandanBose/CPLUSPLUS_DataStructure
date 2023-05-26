// Infix to Postfix Conversion

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

typedef struct Stack
{
    int top;
    int size;
    char *s;

} Stack;

void create(Stack *st, int cap)
{
    st->size = cap;
    st->top = -1;
    st->s = (char *)malloc(st->size * sizeof(char));
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

void push(Stack *st, char x)
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

char pop(Stack *st)
{
    if (isEmpty(*st))
    {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
    return st->s[st->top--];
}

int pre(char x)
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

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^' || x == '%')
    {
        return 0;
    }
    return 1;
}

char *InToPost(char *infix)
{
    Stack st;
    int len = strlen(infix);                                  // Calculate the length of the string
    char *postfix = (char *)malloc((len + 1) * sizeof(char)); // Allocate the memory for postfix string
    create(&st, len);                                         // Create the stack

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]) == 1)
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (pre(infix[i]) > pre(st.s[st.top]) || isEmpty(st) || infix[i] == '(')
            {
                push(&st, infix[i]);
                i++;
            }
            else if (pre(infix[i]) <= pre(st.s[st.top]) && infix[i] == ')')
            {
                while (st.s[st.top] != '(')
                {
                    postfix[j] = pop(&st);
                    j++;
                }
                pop(&st);
                i++;
            }
            else
            {
                while (pre(infix[i]) <= pre(st.s[st.top]) && !isEmpty(st) && st.s[st.top] != '(' && st.s[st.top] != ')')
                {

                    postfix[j] = pop(&st);
                    j++;
                }
                push(&st, infix[i]);
                i++;
            }
        }
    }

    while (!isEmpty(st))
    {
        postfix[j] = pop(&st);

        j++;
    }

    postfix[j] = '\0';

    free(st.s);

    return postfix;
}

int postfixEvaluation(char *postfix)
{
    Stack st;
    create(&st, strlen(postfix));

    int i = 0;
    int r, op1, op2;

    while (postfix[i] != '\0')
    {
        if (isOperand(postfix[i]))
        {
            push(&st, postfix[i] - '0');
        }
        else
        {
            op2 = pop(&st);
            op1 = pop(&st);

            switch (postfix[i])
            {
            case '+':
                r = op1 + op2;
                break;
            case '-':
                r = op1 - op2;
                break;
            case '*':
                r = op1 * op2;
                break;
            case '/':
                r = op1 / op2;
                break;
            case '%':
                r = op1 % op2;
                break;
            case '^':
                r = pow(op1, op2);
                break;
            default:
                cout << "Invalid Operator" << endl;
                return 0;
            }
            push(&st, r);
        }
        i++;
    }
    return pop(&st);
}

int main()
{
    int size;
    char *infix;
    cout << "Enter the size of the infix expression" << endl;
    cin >> size;
    infix = (char *)malloc((size) * sizeof(char)); // Allocate the memory for infix string

    cout << "Enter the infix expression" << endl;
    cin >> infix;

    cout << "The postfix expression is" << endl;

    char *postfix = InToPost(infix);

    cout << postfix << endl;

    cout<<"The result of the postfix expression is "<<postfixEvaluation(postfix)<<endl;


    free(infix);

    return 0;
}


