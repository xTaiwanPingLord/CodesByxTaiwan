#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string magicbook, question, temp, prev;
    map<int, int> magicmap;
    int len, quiz, T, X;

    cin >> magicbook;
    cin >> len >> quiz;
    cin >> question;

    for (int i = 0; i < 26; i++)
    {
        magicmap[magicbook[i] - 65] = i; // (char) 'A' == 65
    }

    for (int loop = 0; loop < quiz; loop++)
    {
        cin >> T >> X;
        prev = question;
        for (int i = 0; i < T; i++)
        {
            temp.assign(len, ' ');
            for (int j = 0; j < len; j++)
                temp[magicmap[j]] = prev[j];
            prev = temp;
        }
        cout << prev[X - 1] << "\n";
    }
}