//Fibonacci Series through Recursion

// This code prints the Fibonacci series using recursion. The Fibonacci series is a series of numbers where the next number is the sum of the previous two numbers. The first two numbers of the series are 0 and 1. The series is as follows: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, etc.

#include <iostream>

using namespace std;

int fibonacci(int n) // Function to calculate the nth Fibonacci number
{
    if (n == 0 || n == 1) // Base case
    {
        return n; // If n is 0 or 1, return n
    }
    return fibonacci(n-1) + fibonacci(n-2); // Recursive call : nth Fibonacci number is the sum of (n-1)th and (n-2)th Fibonacci number
}

int main() // Main function
{
    int n; // Number of terms
    cout << "Enter the number of terms: "; // Input the number of terms
    cin >> n; // Store the number of terms
    cout << "The Fibonacci series is: "; // Output the Fibonacci series
    for (int i = 0; i < n; i++) // Loop to print the first n Fibonacci numbers
    {
        cout << fibonacci(i) << " "; // Print the ith Fibonacci number
    }
    return 0; // Return statement
}