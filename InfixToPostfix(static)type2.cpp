#include <iostream>
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

        if (isalnum(ch))
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

int main()
{
    char infix[100];
    cout << "Enter an infix expression: ";
    cin.getline(infix, 100);

    char postfix[100];
    InfixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}


//Replacing the isOperand() function with isalnum function
// isalnum() checks whether the passed character is alphanumeric or not.
//Alpha Numeric means alphabets (a-z, A-Z) and numbers (0-9).
//It returns a non-zero integer if the character passed is alphanumeric, else it returns 0.