#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    char *s;

public:
    Stack(int capacity)
    {
        size = capacity;
        top = -1;
        s = new char[size];
    }

    ~Stack()
    {
        delete[] s;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    int peek()
    {
        if (isEmpty())
        {

            return -1;
        }
        return s[top];
    }

    void push(char x)
    {
        if (isFull())
        {
            return;
        }
        else
        {
            top++;
            s[top] = x;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        return s[top--];
    }
};

class InfixToPostfixConverter
{
private:
    Stack st;

public:
    InfixToPostfixConverter(int capacity) : st(capacity) {} // Above constructor is called

    int precedence(char x)
    {
        switch (x)
        {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '%':
            return 4;
        case '(':
        case ')':
            return 0;
        default:
            return -1;
        }
    }

    bool isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^' || x == '%')
        {
            return false;
        }
        return true;
    }

    char *convertToPostfix(char *infix)

    {

        int len = strlen(infix);                                 
        char *prefixExpr = new char[len];
        int i = len - 1, j = 0; 

        while (i >= 0)
        {
            if (isOperand(infix[i]))
            {
                prefixExpr[j] = infix[i];
                j++;
                i--;
            }
            else
            {
                if (precedence(infix[i]) > precedence(st.peek()) || st.isEmpty() || infix[i] == ')')
                {
                    st.push(infix[i]);
                    i--;
                }
                else if (precedence(infix[i]) <= precedence(st.peek()) && infix[i] == '(')
                {
                    while (st.peek() != ')')
                    {
                        prefixExpr[j] = st.pop();
                        j++;
                    }
                    st.pop();
                    i--;
                }
                else
                {
                    while (precedence(infix[i]) <= precedence(st.peek()) && !st.isEmpty() && infix[i] != '(' && infix[i] != ')')
                    {
                        prefixExpr[j] = st.pop();
                        j++;
                    }
                    st.push(infix[i]);
                    i--;
                }
            }
        }

        while (!st.isEmpty())
        {
            prefixExpr[j] = st.pop();
            j++;
        }

        prefixExpr[j] = '\0';

        // Reverse the prefix expression to get the correct order
        int start = 0;
        int end = strlen(prefixExpr) - 1;
        while (start < end)
        {
            char temp = prefixExpr[start];
            prefixExpr[start] = prefixExpr[end];
            prefixExpr[end] = temp;
            start++;
            end--;
        }

        st.~Stack();
        return prefixExpr;
    }

   
};


int main()
{
    int size;
    cout << "Enter the size of the infix expression: ";
    cin >> size;
    char *infix = new char[size];
    cout << "Enter the infix expression: ";
    cin >> infix;
    InfixToPostfixConverter ip(size);
    cout << ip.convertToPostfix(infix) << endl;
    return 0;
}