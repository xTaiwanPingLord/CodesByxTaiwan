#include <bits/stdc++.h>
using namespace std;

void write(vector<bool> &vct, const int &start, const int &end)
{
    for (int i = start; i <= end; i++)
        vct[i] = true;
}

bool check(vector<bool> &vct, const int &start, const int &end)
{
    for (int i = start; i <= end; i++)
    {
        if (vct[i] == true)
            return false;
    }
    return true;
}

int main()
{
    int num_event, num_machine;
    cin >> num_event >> num_machine;

    vector<vector<int>> event(num_event, vector<int>(3, 0)); // start, end, time used
    for (int i = 0; i < 2; i++)
    {
        for (auto j = 0; j < num_event; j++)
            cin >> event[j][i];
    }
    for (int i = 0; i < num_event; i++) // calc time used
        event[i][2] = event[i][1] - event[i][0];

    sort(event.begin(), event.end(), // sort by start time first
         [](vector<int> a, vector<int> b) -> bool
         { return a[0] < b[0]; });

    sort(event.begin(), event.end(), // then sort by time used
         [](vector<int> a, vector<int> b) -> bool
         { return a[2] < b[2]; });

    vector<vector<bool>> machine(num_machine, vector<bool>(10e8 + 1));
    int ans = 0;
    for (int i = 0; i < num_event; i++)
    {
        for (int j = 0; j < num_machine; j++)
        {
            if (check(machine[j], event[i][0], event[i][1]))
            {
                write(machine[j], event[i][0], event[i][1]);
                ans++;
                break;
            }
        }
    }

    // for (int i = 0; i < num_event; i++) // print event vector
    //     cout << event[i][0] << " " << event[i][1] << " " << event[i][2] << " \n";
    cout << ans;
}