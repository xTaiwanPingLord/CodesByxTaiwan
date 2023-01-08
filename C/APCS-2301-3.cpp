#include <bits/stdc++.h>
using namespace std;

uint64_t to_ll(const string &s)
{
    uint64_t out = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        out += (s[s.size() - 1 - i] - '0') * pow(10, i);
    }
    return out;
}

uint64_t parse(const string &s)
{
    int type = 0, prev_type = 0;
    int idx_r = -1, idx_l = -1;
    int len = (int)s.size();

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '*')
        {
            type = 3;
        }
        else if (s[i] == '+')
        {
            type = 2;
        }
        else if (s[i] == '(') // f(
        {
            type = 1;
        }

        if (type > prev_type)
        {
            prev_type = type;
            idx_l = i;
            cout << "str: " << s << " | type: " << type << " | idx(L,R): " << idx_l << ", " << idx_r << " | substr(L,R): " << s.substr(0, idx_l) << ", " << s.substr(idx_l + 1) << "\n";
            cout.flush();
        }
    }

    if (prev_type == 0)
        return to_ll(s);
    else if (prev_type == 3)
        return parse(s.substr(0, idx_l)) * parse(s.substr(idx_l + 1));
    else if (prev_type == 2)
        return parse(s.substr(0, idx_l)) + parse(s.substr(idx_l + 1));
    else
        return 99999999;
}

int main()
{
    string in;
    cin >> in;

    cout << parse(in);
}