#include <iostream>
#include <cctype>
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

char *InfixToPrefix(string &infix, string &prefix)
{
    int len = infix.length();
    int i = len - 1, j = 0;

    while (i >= 0)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            prefix.push_back(ch);
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
                    prefix.push_back(pop());
                    j++;
                }
                pop();
                i--;
            }
            else
            {
                while (pre(ch) <= pre(peek()) && top != -1 && ch != '(' && ch != ')')
                {
                    prefix.push_back(pop());
                    j++;
                }
                push(ch);
                i--;
            }
        }
    }

    while (top != -1)
    {
        prefix.push_back(pop());
        j++;
    }

    // Reverse the prefix expression
    int start = 0;
    int end = prefix.length() - 1;
    while (start < end)
    {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }

    return &prefix[0];
}

double evaluatePrefix(string &prefix)
{
    int len = prefix.length();
    int i = len - 1;

    while (i >= 0)
    {
        char ch = prefix[i];

        if (isalnum(ch))
        {
            push(ch - '0');
            i--;
        }
        else
        {
            double op1 = pop();
            double op2 = pop();

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
                push((int)op1 % (int)op2);
                break;
            }
            i--;
        }
    }

    return pop();
}

int main()
{
    string infix;
    string prefix;

    cout << "Enter an infix expression: ";
    cin >> infix;
    InfixToPrefix(infix, prefix);
    cout <<"Infix To Prefix Conversion:" << prefix << endl;

    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}
