#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> tree;
    stack<int> history;
    uint64_t ans = 0;
    int input, prev;

    cin >> input;
    tree.push(input);
    history.push(-1);

    while (!tree.empty())
    {
        prev = (uint64_t)tree.top();
        history.top()++;
        // cout << tree.top() << " " << history.top() << "\t| prev: " << prev << "\t| " << ans << endl;

        if (tree.top() % 2 + 2 == history.top())
        {
            tree.pop();
            history.pop();
        }
        else
        {
            cin >> input;
            tree.push(input);
            history.push(-1);
            if (input == 0)
            {
                tree.pop();
                history.pop();
                continue;
            }
            ans += abs(input - prev);
        }
    }
    cout << ans;
}