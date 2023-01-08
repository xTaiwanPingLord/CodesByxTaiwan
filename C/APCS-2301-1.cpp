#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int max_score = -99, max_time = 0, bad_count = 0;
    int score;
    int input_score, input_time;

    for (int i = 0; i < num; i++)
    {
        cin >> input_time >> input_score;
        if(input_score > max_score)
        {
            max_time = input_time;
            max_score = input_score;
        }
        if(input_score == -1)
        {
            bad_count++;
        }
    }

    score = max_score - num - bad_count * 2;
    if(score < 0)
        score = 0;

    cout << score << " " << max_time;
}