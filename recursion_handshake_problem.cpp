//Handshake Problem Recursion

// This code calculates the number of handshakes that occur when a given number of people are in a room. It uses recursion to calculate the number of handshakes based on the number of people. 
#include <iostream>
using namespace std;

int handshake(int n) // Function to calculate the number of handshakes              
{
    if (n == 0 || n == 1) // Base case
    {
        return 0; // If there is only one person in the room, there are no handshakes
    } 
    cout<<n <<endl;
    return handshake(n-1)+(n-1); // Recursive call : n-1 people shake hands with each other and the remaining person shakes hands with n-1 people
}

int main() // Main function
{
    int n; // Number of people
    cout << "Enter the number of people: "; // Input the number of people
    cin >> n;// Store the number of people
    cout << "The number of handshakes are: " << handshake(n);// Output the number of handshakes
    return 0;// Return statement
}

