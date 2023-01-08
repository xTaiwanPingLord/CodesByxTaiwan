#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void print(vector<pair<int, int>> &input)
{
    for (auto &i : input)
        cout << i.first << "\t" << i.second << "\n";
}

int main()
{
    int num, len, max_h = 0;
    cin >> num >> len;

    vector<pair<int, int>> tree(num, pair<int, int>(0, 0));
    vector<pair<int, int>> dist(num, pair<int, int>(0, 0));

    for (auto &i : tree)
        cin >> i.first;
    for (auto &i : tree)
        cin >> i.second;

    print(tree);

    cout << endl;

    sort(tree.begin(), tree.end(), sortbysec);
    print(tree);

}