#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack
int top = -1;             // Global variable
char stack[MAX_SIZE];     // Stack array

void push(char item)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    top++;
    stack[top] = item;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top--];
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^' || x == '%')
    {
        return 0;
    }
    return 1;
}

int peek()
{
    if (top == -1)
    {
        return -1;
    }

    return stack[top];
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

char *InfixToPrefix(char infix[], char prefix[])
{
    int len = strlen(infix);
    int i = len - 1, j = 0;

    while (i >= 0)
    {

        char ch = infix[i];

        if (isOperand(ch))
        {
            prefix[j] = ch;
            j++;
            i--;
        }
        else
        {
            if (pre(ch) > pre(peek()) || top == -1 || ch == ')')
            {
                push(ch);
                i--;
            }
            else if (pre(ch) <= pre(peek()) && ch == '(')
            {
                while (peek() != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i--;
            }
            else
            {
                while (pre(ch) <= pre(peek()) && top != -1 && ch != '(' && ch != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                push(ch);
                i--;
            }
        }
    }

    while (top != -1)
    {
        prefix[j] = pop();
        j++;
    }

    prefix[j] = '\0';

    // Reverse the prefix expression
    int start = 0;
    int end = strlen(prefix) - 1;
    while (start < end)
    {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }

   return prefix;
}

double evaluatePrefix(char prefix[])
{
    int len = strlen(prefix);
    int i = len - 1;

    while (i >= 0)
    {
        char ch = prefix[i];

        if (isOperand(ch))
        {
            push(ch - '0');
            
        }
        else
        {
            int op1 = pop();
            int op2 = pop();

            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '^':
                push(pow(op1, op2));
                break;
            case '%':
                push(op1 % op2);
                break;
            }
            
        }
        i--;
    }

    return pop();
}

 

int main()
{
    char infix[100];
    char prefix[100];

    cout << "Enter an infix expression: ";
    // cin.getline(infix, 100);
    cin >> infix;

    cout << "Infix To Prefix :" << InfixToPrefix(infix, prefix) << endl;

    cout << "Evaluating the Prefix Expression:" << evaluatePrefix(prefix) << endl;

    return 0;
}
