#include <bits/stdc++.h>
using namespace std;

void sort_by_end_time(vector<int> &seq, const vector<int> &busy, const int &start_time)
{
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

    int ans = 0;
    vector<int> machine_busy(num_machine, 0);
    vector<int> machine_seq(num_machine, 0);

    for (int i = 0; i < num_machine; i++)
        machine_seq[i] = i;

    for (int i = 0; i < num_event; i++)
    {
        sort(machine_seq.begin(), machine_seq.end(),
             [&](int a, int b) -> bool
             { return event[i][a] - machine_busy[a] < event[i][b] - machine_busy[b]; });

        for (const int &j : machine_seq)
        {
            if (machine_busy[j] < event[i][0])
            {
                machine_busy[j] = event[i][1];
                ans++;
                break;
            }
        }
    }

    // for (int i = 0; i < num_event; i++) // print event vector
    //     cout << event[i][0] << " " << event[i][1] << " " << event[i][2] << " \n";
    cout << ans;
}