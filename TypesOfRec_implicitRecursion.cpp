//Product of all elements in a vector using recursion

#include <iostream>
#include <vector>

using namespace std;

int calculateProduct(vector<int> &numbers)
{
    if (numbers.empty())
    {
        return 1;
    }
    else
    {

        int firstElement = numbers[0];
        vector<int> remainingNumbers(numbers.begin() + 1, numbers.end());
        
        
        int productOfRemaining = calculateProduct(remainingNumbers);
        
        return firstElement*productOfRemaining;
    }
}

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};

    int product = calculateProduct(numbers);
     cout << "The product of all elements is: " << product << endl;

    return 0;
}
