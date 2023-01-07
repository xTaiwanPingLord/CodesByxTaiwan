#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<string> straw(num);
    string temp;
    int count = 0;
    for (auto &i : straw)
        cin >> i;

    sort(straw.begin(), straw.end());
    
    for (auto i = 0; i < num; i++)
    {
        for (auto j = 1; (uint64_t)j * 2 < straw[i].size(); j++)
        {
            temp = straw[i].substr(0, j);
            if(temp != straw[i].substr(straw[i].size() - j))
                continue;

            temp = straw[i].substr(j, straw[i].size() - j * 2);

            if(binary_search(straw.begin(), straw.end(), temp))
                count++;
        }
    }
    cout << count;
}