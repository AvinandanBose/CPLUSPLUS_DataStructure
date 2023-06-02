// Prefix Evaluation using Dynamic Stack Using Malloc

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

char *InToPre(char *infix)
{
    Stack st;
    int len = strlen(infix);                                 // Calculate the length of the string
    char *prefixExpr = (char *)malloc((len) * sizeof(char)); // Allocate the memory for prefix string
    create(&st, len);                                        // Create the stack

    int i = len - 1, j = 0; // Start from the end of infix expression

    while (i >= 0)
    {
        if (isOperand(infix[i]) == 1)
        {
            prefixExpr[j] = infix[i];
            j++;
            i--;
        }
        else
        {
            if (pre(infix[i]) > pre(st.s[st.top]) || isEmpty(st) || infix[i] == ')')
            {

                push(&st, infix[i]);
                i--;
            }
            else if (pre(infix[i]) <= pre(st.s[st.top]) && infix[i] == '(')
            {
                while (st.s[st.top] != ')')
                {
                    prefixExpr[j] = pop(&st);
                    j++;
                }
                pop(&st);
                i--;
            }
            else
            {
                while (pre(infix[i]) <= pre(st.s[st.top]) && !isEmpty(st) && infix[i] != '(' && infix[i] != ')')
                {

                    prefixExpr[j] = pop(&st);

                    j++;
                }
                push(&st, infix[i]);
                i--;
            }
        }
    }

    while (!isEmpty(st))
    {
        prefixExpr[j] = pop(&st);
        j++;
    }

    prefixExpr[j] = '\0';

    // Reverse the prefix expression to get the correct order
    int start = 0;
    int end = j - 1;
    while (start < end)
    {
        char temp = prefixExpr[start];
        prefixExpr[start] = prefixExpr[end];
        prefixExpr[end] = temp;
        start++;
        end--;
    }

    free(st.s);

    return prefixExpr;
}

int prefixEvaluation(char *prefix)
{
    Stack st;
    int len = strlen(prefix);
    create(&st, len);

    int i = len - 1;

    int r, op1, op2;

    while (i >= 0 )
    {
        if (isOperand(prefix[i]) == 1)
        {
            push(&st, prefix[i] - '0');
        }
        else
        {
            op1 = pop(&st);

            op2 = pop(&st);
        

            switch (prefix[i])
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
            case '^':
                r = pow(op1, op2);
                break;
            case '%':
                r = op1 % op2;
                break;
            }
            push(&st, r);
        }
        i--;
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

    cout << "The prefix expression is" << endl;

    char *prefix = InToPre(infix);

    cout << prefix << endl;

    cout << "The result of the prefix expression is" << endl;

    cout << prefixEvaluation(prefix) << endl;

    return 0;
}