#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> my_vector(5, 10);

    for (auto i : my_vector)
    {
        cout << " " << i;
    }
    cout << " " << *my_vector.end();
    my_vector.erase(my_vector.end());

    for (auto i : my_vector)
    {
        cout << " " << i;
    }

    my_vector.insert(my_vector.begin() + 1, 15);

    for (auto i : my_vector)
    {
        cout << " " << i;
    }
}