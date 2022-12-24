#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num_string, num_ops;
    cin >> num_string >> num_ops;
    cin.get();

    vector<string> texts(num_string);
    for (string &i : texts)
    {
        getline(cin, i);
    }

    string clipboard, op;
    int line, left, right;
    for (int loop = 0; loop < num_ops; loop++)
    {
        cin >> op;
        if(op == "cut")
        {
            cin >> line >> left >> right;
            clipboard = texts[line].substr(left, right - left + 1);
            texts[line].erase(left, right - left + 1);
        }
        else
        {
            cin >> line >> left;
            texts[line].insert(left, clipboard);
        }
    }

    for (const string &i : texts)
    {
        cout << i << "\n";
    }
}