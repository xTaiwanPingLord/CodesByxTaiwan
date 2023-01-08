#include <bits/stdc++.h>
using namespace std;

int main()
{
    int string_len, output_len, output_line;
    cin >> string_len >> output_len >> output_line;

    vector<string> str(output_len + 1, string(string_len, ' '));
    cin >> str[0]; 

    int index;
    for (int i = 1; i <= output_len; i++)
    {
        for (int j = 0; j < string_len; j++)
        {
            cin >> index;
            str[i][index - 1] = str[i - 1][j]; // 將上個字串 j 放到，新的字串 index(輸入) 的位置
        }
    }

    for (int i = 0; i < output_line; i++)
    {
        for (int j = 1; j <= output_len; j++) // str[0]原始字串不用輸出，注意輸出的排列方向
            cout << str[j][i];
        cout << "\n";
    }
}