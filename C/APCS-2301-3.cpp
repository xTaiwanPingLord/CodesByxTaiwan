#include <bits/stdc++.h>
using namespace std;

// declaring some function
uint64_t f(const string &s);
uint64_t parse(const string &s);
uint64_t to_ll(const string &s);

uint64_t to_ll(const string &s) // convert string to long long
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
    int idx = -1;
    int layer;
    int len = (int)s.size();

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '*')
            type = 3;
        else if (s[i] == '+')
            type = 2;
        else if (s[i] == '(') // f(
        {
            type = 1;
            layer = 0;
            for (; i < len; i++) // 1. 解析嵌套的括號 如: ( (左右的括號跳過) ) ，以跳過f()中的+以及*，
            {
                if (s[i] == '(')
                    layer++; // starting from 1 here
                else if (s[i] == ')')
                    layer--;
                if (layer == 0)
                    break;
            }
        }

        if (type > prev_type) // 找到的運算符號 優先級更高
        {
            prev_type = type;
            idx = i;
        }
    }

    if (prev_type == 0) // 如果沒有運算符號，回傳數字
        return to_ll(s);
    else if (prev_type == 3) // 切字串，分別計算運算符號前後的兩個字串
        return parse(s.substr(0, idx)) * parse(s.substr(idx + 1));
    else if (prev_type == 2)
        return parse(s.substr(0, idx)) + parse(s.substr(idx + 1)); 
    else if (prev_type == 1)
        return f(s); // 把整個字串丟給f()處理 這邊字串只會出現 "f(1+2, 3)" 之類的，不用再切
    else
        return 99999999; 
}

uint64_t f(const string &s)
{
    uint64_t max_num = 0, min_num = INT64_MAX -1, num;
    int idx_l = -1, idx_r = 1, len = (int)s.size();
    int layer = 0;
    for (int i = 2; i < len; i++) // 從f( 也就是第3個字元開始。
    {
        if ((s[i] == ',' || s[i] == ')') && layer == 0) // 對每個以,分隔的參數做運算，取最大最小值
        {
            idx_l = idx_r + 1;
            idx_r = i;
            num = parse(s.substr(idx_l, idx_r - idx_l));
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        if (s[i] == '(') // 解析嵌套的括號 (())
            layer++;
        else if (s[i] == ')' && layer != 0)
            layer--;
    }
    return max_num - min_num;
}

int main()
{
    string in;
    cin >> in;

    cout << parse(in);
}