#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int function(int input)
{
    if (input <= 100)
    {
        return function(function(input + 11));
    }
    else
    {
        return (input - 10);
    }
}

int main()
{
    int data, output;

    while (true)
    {
        cin >> data;
        if (data == 0)
        {
            return 0;
        }
        output = function(data);
        cout << "f91(" << data << ") = " << output << "\n";
    }
}