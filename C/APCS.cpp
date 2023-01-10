#include <bits/stdc++.h>
using namespace std;

#ifdef FMT_DEBUG
#define FMT_HEADER_ONLY
#include <fmt/include/fmt/core.h>
#else
namespace fmt
{
    void format(...) { return; };
    void print(...) { return; };
    void join(...) { return; };
};
#endif

template <typename T>
inline T ReadOne()
{
    T temp;
    std::cin >> temp;
    return temp;
}

/////////////////////////////////////////////////////////////////

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

void print(vector<pair<int, int>> &input)
{
#ifndef FMT_DEBUG
    return;
#endif
    cout << "\n";
    for (auto &i : input)
        cout << i.first << "\t" << i.second << "\n";
    cout << "\n"
         << flush;
}

int cut(bool &foundtree, int &i, int &count, int &num, vector<pair<int, int>> &tree)
{
    int ans;
    ans = tree[i].second;
    foundtree = true;
    count++;
    tree.erase(tree.begin() + i);
    num--;
    i--;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool foundtree = false;
    int num, len, max_h = 0, count = 0;
    cin >> num >> len;

    // list<pair<int, int>> tree(num, pair<int, int>(0, 0));
    vector<pair<int, int>> tree(num, pair<int, int>(0, 0));
    // vector<pair<int, int>> dist(num, pair<int, int>(0, 0));

    for (auto &i : tree)
        cin >> i.first;
    for (auto &i : tree)
        cin >> i.second;

    print(tree);

    // sort(tree.begin(), tree.end(), sortbysec);

    do
    {
        foundtree = false;
        for (int i = 0; i < num; i++)
        {
            if (i == 0)
            {
                if (tree[i].first - tree[i].second >= 0 || tree[i].first + tree[i].second <= min(len, tree[i + 1].first))
                    max_h = max(cut(foundtree, i, count, num, tree), max_h);
            }
            else if (i == num - 1)
            {
                if (tree[i].first - tree[i].second >= max(0, tree[i - 1].first) || tree[i].first + tree[i].second <= len)
                    max_h = max(cut(foundtree, i, count, num, tree), max_h);
            }
            else if (tree[i].first - tree[i].second >= max(0, tree[i - 1].first) || tree[i].first + tree[i].second <= min(len, tree[i + 1].first))
                max_h = max(cut(foundtree, i, count, num, tree), max_h);
            print(tree);
        }
    } while (foundtree);

    cout << count << "\n"
         << max_h;
}