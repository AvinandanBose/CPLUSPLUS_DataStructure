#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

int top = -1;         // Global variable
char stack[MAX_SIZE]; // Stack array

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

void InfixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isOperand(ch))
        {
            postfix[j] = ch;
            i++;
            j++;
        }
        else
        {
            if (pre(ch) > pre(peek()) || top == -1 || ch == '(')
            {
                push(ch);
                i++;
            }
            else if (pre(ch) <= pre(peek()) && ch == ')')
            {
                while (peek() != '(')
                {
                    postfix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }
            else
            {
                while (pre(ch) <= pre(peek()) && top != -1 && ch != '(' && ch != ')')
                {
                    postfix[j] = pop();
                    j++;
                }
                push(ch);
                i++;
            }
        }
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
}

int EvaluatePostfix(char postfix[])
{
    int i = 0;
    int result = 0;
    int operand1, operand2;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        if (isOperand(ch))
        {
            push(ch - '0');
        }
        else
        {
            operand2 = pop();
            operand1 = pop();

            switch (ch)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '^':
                push(pow(operand1, operand2));
                break;
            default:
                cout << "Invalid operator encountered!" << endl;
                return 0;
            }
        }
        i++;
    }

    result = pop();
    return result;
}

int main()
{
    char infix[100];
    cout << "Enter an infix expression: ";
    cin.getline(infix, 100);

    char postfix[100];
    InfixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    cout << "Result: " << EvaluatePostfix(postfix) << endl;

    return 0;
}
