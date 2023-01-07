#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<string> straw(num);
    string temp;
    int half;
    int count = 0;
    bool is_true;
    for (auto &i : straw)
        cin >> i;

    for (auto i = 0; i < num; i++)
    {
        for (auto j = i + 1; j < num; j++)
        {
            temp = straw[i] + straw[j];
            half = temp.length();
            if (half % 2 == 0)
                half = half / 2;
            else
                continue;
            
            is_true = true;
            for (auto k = 0; k < half; k++)
            {
                if (temp[k] != temp[k + half])
                {
                    is_true = false;
                    break;
                }
            }
            if (is_true)
                count++;
            // binary_search()
        }
    }
    cout << count;
}