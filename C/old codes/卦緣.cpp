#include <iostream>
using namespace std;

int main()
{
    int cases, people, couple, guy0, guy1, rainbow = 0;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        cin >> people >> couple;
        int relation[200000];
        for (int i = 0; i < 200000; i++)
        {
            relation[i] = 0;
        }

        for (int k = 0; k < couple && rainbow != 1; k++)
        {
            cin >> guy0 >> guy1;
            rainbow = 0;
            // 0=not defined 1=male 2=female
            if (relation[guy0] == 0 && relation[guy1] == 0)
            {
                if ((guy0 % 2) == 0)
                {
                    relation[guy0] = 1;
                    relation[guy1] = 2;
                }
                else
                {
                    relation[guy0] = 2;
                    relation[guy1] = 1;
                } //"應該可以減少一些"順序上的問題
            }
            else if (relation[guy0] != 0 && relation[guy1] == 0)
            {
                if (relation[guy0] == 1)
                {
                    relation[guy1] = 2;
                }
                else
                {
                    relation[guy1] = 1;
                }
            }

            else if (relation[guy0] == 0 && relation[guy1] != 0)
            {
                if (relation[guy1] == 1)
                {
                    relation[guy0] = 2;
                }
                else
                {
                    relation[guy0] = 1;
                }
            }
            else if (relation[guy0] != 0 && relation[guy1] != 0)
            {
                if (relation[guy0] == relation[guy1])
                {
                    rainbow = 1;
                }
            }
        }
        // for (int k = 0; k < people; k++)
        // {
        //     cout << k << ": " << relation[k] << endl;
        // }

        if (rainbow == 1)
        {
            cout << "RAINBOW." << endl;
            rainbow = 0;
        }
        else
        {
            cout << "NORMAL." << endl;
        }
    }
}