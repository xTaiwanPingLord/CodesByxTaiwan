#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Num, K;
    cin >> Num >> K;

    vector<int> people(2 * Num, 0);
    for (int i = 0; i < 2 * Num; i += 2)
    {
        cin >> people[i];
    }
    for (int i = 1; i < 2 * Num; i+=2)
    {
        people[i] = K - people[i - 1];
    }
    
}