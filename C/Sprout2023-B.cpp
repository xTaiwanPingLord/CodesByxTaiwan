#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string magicbook, question, temp, prev;
    map<int, char> magicmap;
    int len, num_quiz, T, X, count;

    cin >> magicbook;
    cin >> len >> num_quiz;
    cin >> question;

    for (int i = 0; i < 26; i++)
    {
        magicmap[i] = magicbook[i];
    }

    for (int loop = 0; loop < num_quiz; loop++)
    {
        count = 0;
        cin >> T >> X;
        prev = question;
        for (int i = 0; i < T; i++)
        {
            temp.assign(len, ' ');
            for (int j = 0; j < len; j++)
                temp[j] = magicmap[prev[j] - 65]; // (char) 'A' == 65
            prev = temp;
            count++;

            if (prev == question) // 找到規律
            {
                T = T % count;
                i = -1; // -1 becuz i++
                prev = question;
            }
        }
        cout << prev[X - 1] << "\n";
    }
}