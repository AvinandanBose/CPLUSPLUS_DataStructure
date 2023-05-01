#include <iostream>
using namespace std;

int main(int argc, char *argv[], char *envp[])
{
    cout << "The number of arguments 'argc'=: " << argc << endl;
    cout << "The arguments are: " << endl;

    for (int i = 0; i < argc; i++)
    {
        cout << "argv["<<i<<"]="<<argv[i] << endl;
    }

    cout << "The environment variables are: " << endl;

    for (int i = 0; envp[i] != NULL; i++)
    {
        cout << "envp["<<i<<"]="<<envp[i] << endl;
    }
    return 0;
}