// Tower of Hanoi

#include <iostream>
using namespace std;

void toh(int n, char src, char dest, char aux)
{
    if (n == 0)
    {
        return ;
    }

    
    toh(n - 1, src, aux, dest);
   
    cout << "Move " << n << " from " << src << " to " << dest << endl;

    toh(n - 1, aux, dest, src);
}

int main()
{

    toh(3, 'A', 'C', 'B');
    return 0;
}