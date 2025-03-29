// Importing the necessary libraries
#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int factorial(int n)
{
    // Base case: if n is 0 or 1, return 1
    // This is because the factorial of 0 and 1 is 1
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        // Recursive case: n times factorial of n-1
        // This is the definition of factorial: the product of an integer and all the integers below it
        return n * factorial(n - 1);
    }
}

// Main function
int main()
{
    // Variable to store the user input
    int n;
    // Prompt the user to enter a number
    cout << "Enter a number: ";
    // Store the user input in the variable n
    cin >> n;
    // Print the factorial of the entered number
    // The factorial function is called here with the user input as the argument
    cout << "Factorial of " << n << " = " << factorial(n);

    // Return 0 to indicate that the program has run successfully
    return 0;
}