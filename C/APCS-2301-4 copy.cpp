// #define FMT_HEADER_ONLY
// #include <fmt/include/fmt/core.h>

#include <bits/stdc++.h>
using namespace std;

bool comp(int *a, int *b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num_event, num_machine;
    cin >> num_event >> num_machine;

    int event[num_event][2]; // start, end
    for (int i = 0; i < num_event; i++)
        cin >> event[i][0];
    for (int i = 0; i < num_event; i++)
        cin >> event[i][1];

    sort(event, event + num_event, comp); // sort by end time first, if same sort by start time (small -> large)

    // for (int i = 0; i < num_event; i++)
    //     fmt::print("{}: {}\n", i, fmt::join(event[i], ", "));

    int ans = 0, which_machine_max = -10;
    int machine_busy[num_machine];
    memset(machine_busy, -1, sizeof(int) * num_machine);

    for (int i = 0; i < num_event; i++) // 掃過每個event
    {
        for (int j = 0; j < num_machine; j++)
        {
            if (machine_busy[j] < event[i][0] && which_machine_max == -10)                                // if機器可用且沒有其他數字。如果放到下面，machine_busy[which_machine_max] 會超過範圍。
                which_machine_max = j;                                                                    // 存index
            else if (machine_busy[j] < event[i][0] && machine_busy[j] >= machine_busy[which_machine_max]) // if機器可用且最大
                which_machine_max = j;                                                                    // 存index
        }
        // fmt::print("\nwhich_machine_max: {}\nmachine busy: {}\nevent: {}\nans: {}\n", which_machine_max, fmt::join(machine_busy, ", "), fmt::join(event[i], ", "), ans);

        if (which_machine_max != -10)
        {
            machine_busy[which_machine_max] = event[i][1];
            ans++;
            which_machine_max = -10;
        }
    }

    cout << ans << endl;
}