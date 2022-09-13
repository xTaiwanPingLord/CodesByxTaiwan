#include <iostream>
#define swap(x, y)   \
    {                \
        float t = x; \
        x = y;       \
        y = t;       \
    }

using namespace std;
int main()
{
    int cap, qty, capNow = 0, value = 0;
    cin >> cap >> qty;
    float backpack[qty][3];
    // 0 cap 1 value 2 value per cap
    for (int i = 0; i < qty; i++)
    {
        cin >> backpack[i][0] >> backpack[i][1];
        backpack[i][2] = backpack[i][1] / backpack[i][0];
    }

    for (int k = qty - 1; k != 0; k--)
    {
        for (int q = 0; q < k; q++)
        {
            if (backpack[q][2] >= backpack[k][2])
            {
                swap(backpack[k][2], backpack[q][2]);
                swap(backpack[k][1], backpack[q][1]);
                swap(backpack[k][0], backpack[q][0]);
            }
        }
    }//sort

    for (int i = qty - 1; i >= 0; i--)
    {
        capNow = capNow + backpack[i][0];
        if (capNow <= cap)
        {
            value = value + backpack[i][1];
        }else{
            capNow = capNow - backpack[i][0];
        }
        //cout << capNow << endl;
    }
    cout << value << endl;
    for (int i = 0; i < qty; i++)
    {
        //cout << " cap: " << backpack[i][0] << " value: " << backpack[i][1] << " value per cap: " << backpack[i][2] << endl;
    }
}
