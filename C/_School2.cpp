#include <bits/stdc++.h>
using namespace std;

void my_swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void my_sort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j + 1] < vec[j])
            {
                my_swap(vec[j + 1], vec[j]);
            }
        }
    }
}

int main()
{
    int num_babies, data, time = 0;
    vector<int> time_to_feed;

    cin >> num_babies;
    for (int i = 0; i < num_babies; i++)
    {
        cin >> data;
        time_to_feed.push_back(data);
    }

    // sort(time_to_feed.begin(), time_to_feed.end()); 這算工具嗎:think:
    my_sort(time_to_feed);

    for (int i = 1; i < num_babies; i++)
    {
        time += time_to_feed[i - 1] * (num_babies - i) * 100;
    }

    cout << time;
}
