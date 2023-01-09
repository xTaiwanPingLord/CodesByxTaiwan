#define FMT_HEADER_ONLY
#include <fmt/include/fmt/core.h> 

#include <bits/stdc++.h>
using namespace std;

/********** Good Luck :) **********/

const string kNumbers = "0123456789";

inline bool IsNum(char c)
{
    return '0' <= c && c <= '9';
}

pair<int64_t, size_t> ParseF(const string &s, size_t start);

void Calculate(stack<int64_t> &stk, char op)
{
    assert(stk.size() >= 2);
    int64_t x = stk.top();
    cout << "Called calc, x: " << x;
    stk.pop();
    int64_t y = stk.top();
    cout << ", y: " << y << ", op: " << op;

    stk.pop();
    if (op == '+')
    {
        stk.push(x + y);
    }
    else if (op == '*')
    {
        stk.push(x * y);
    }
    cout << " | stk.top() :" << stk.top() << "\n";
    cout.flush();
}

int64_t ParseRpn(const string &s, size_t l, size_t r)
{
    fmt::print("Called pars, l: {}, r:{} ", l, r);

    stack<int64_t> numbers;
    stack<char> operators;

    for (size_t i = l; i <= r;)
    {
        fmt::print("{} ", s[i]);
        if (IsNum(s[i]))
        {
            size_t rb = s.find_first_not_of(kNumbers, i + 1) - 1;
            int num = stoll(s.substr(i, rb - i + 1));
            numbers.push(num);
            i = rb + 1;
        }
        else
        {
            if (s[i] == 'f')
            {
                auto ret = ParseF(s, i + 1);
                numbers.push(ret.first);
                i = ret.second + 1;
            }
            else if (s[i] == '+')
            {
                operators.push('+');
                ++i;
            }
            else if (s[i] == '*')
            {
                while (!operators.empty() && operators.top() == '+')
                {
                    cout << "\n";
                    Calculate(numbers, '+');
                    operators.pop();
                    cout << "\n";
                }
                operators.push('*');
                ++i;
            }
        }
    }
    fmt::print("\n");

    while (!operators.empty())
    {
        Calculate(numbers, operators.top());
        operators.pop();
    }
    assert(numbers.size() == 1);

    return numbers.top();
}

// start: index of left parenthesis
pair<int64_t, size_t> ParseF(const string &s, size_t start)
{
    // end: index of right parenthesis
    int level = 0, end = -1;
    vector<size_t> pos_comma{start};
    for (size_t i = start + 1; i < s.size(); ++i)
    {
        // debug(s[i]);
        if (s[i] == '(')
        {
            ++level;
        }
        else if (s[i] == ')')
        {
            if (level == 0)
            {
                end = i;
                break;
            }
            --level;
        }
        else if (s[i] == ',' && level == 0)
        {
            pos_comma.push_back(i);
        }
    }
    pos_comma.push_back(end);

    vector<int64_t> numbers;
    for (size_t i = 0; i < pos_comma.size() - 1; ++i)
    {
        numbers.push_back(ParseRpn(s, pos_comma[i] + 1, pos_comma[i + 1] - 1));
    }

    auto mnmx = minmax_element(numbers.begin(), numbers.end());

    return {*mnmx.second - *mnmx.first, end};
}

int main()
{
    string s;
    cin >> s;

    cout << ParseRpn(s, 0, s.size() - 1) << endl;

    return 0;
}
