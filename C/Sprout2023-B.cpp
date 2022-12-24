#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string magicbook, question, temp, prev;
    map<int, char> magicmap;
    int len, num_quiz, T, X, count = 0;
    vector<string> result;

    cin >> magicbook;
    cin >> len >> num_quiz;
    cin >> question;

    for (int i = 0; i < 26; i++)
    {
        magicmap[i] = magicbook[i];
    }
    prev = question;
    do
    {
        result.push_back(prev);
        temp = prev;
        for (int j = 0; j < len; j++)
            temp[j] = magicmap[prev[j] - 65]; // (char) 'A' == 65
        prev = temp;
        count++;
    } while (prev != question);

    for (int loop = 0; loop < num_quiz; loop++)
    {
        cin >> T >> X;
        cout << result[T % count][X - 1] << "\n";
    }
}