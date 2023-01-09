// #define FMT_HEADER_ONLY
// #include <fmt/include/fmt/core.h>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num_event, num_machine;
    cin >> num_event >> num_machine;

    vector<pair<int, int>> event(num_event); // start, end
    for (int i = 0; i < num_event; i++)
        cin >> event[i].first;
    for (int i = 0; i < num_event; i++)
        cin >> event[i].second;

    sort(event.begin(), event.end(), // sort by end time first, if same sort by start time (small -> large)
         [](pair<int, int> a, pair<int, int> b) -> bool
         { if(a.second == b.second) return a.first < b.first;
            else return a.second < b.second; });

    // for (int i = 0; i < num_event; i++)
    //     fmt::print("{}: {}\n", i, fmt::join(event[i], ", "));

    int ans = 0, which_machine_max = -10;
    vector<int> machine_busy(num_machine, -1);

    for (int i = 0; i < num_event; i++) // 掃過每個event
    {
        for (int j = 0; j < num_machine; j++)
        {
            if (machine_busy[j] < event[i].first && which_machine_max == -10)                                // if機器可用且沒有其他數字。如果放到下面，machine_busy[which_machine_max] 會超過範圍。
                which_machine_max = j;                                                                       // 存index
            else if (machine_busy[j] < event[i].first && machine_busy[j] >= machine_busy[which_machine_max]) // if機器可用且最大
                which_machine_max = j;                                                                       // 存index
        }
        // fmt::print("\nwhich_machine_max: {}\nmachine busy: {}\nevent: {}\nans: {}\n", which_machine_max, fmt::join(machine_busy, ", "), fmt::join(event[i], ", "), ans);

        if (which_machine_max != -10)
        {
            machine_busy[which_machine_max] = event[i].second;
            ans++;
            which_machine_max = -10;
        }
    }

    cout << ans << endl;
}