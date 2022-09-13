#include <iostream>
#include <vector>
using namespace std;

void FuncSort(int Func, bool Print);
void FuncSearch(int Func, bool Print);

int ppl = 0, input = 0, searchFor = 0;
vector<vector<int>> table;
vector<int> result;
// 0座號 1國文 2英文 3數學 4總分 5平均

int main()
{
    cout << "輸入人數: ";
    cin >> ppl;

    for (int i = 0; i < ppl; i++) // input
    {
        vector<int> tmp;

        tmp.push_back(i + 1);
        cout << "輸入 " << i + 1 << " 號的國文成績: ";
        cin >> input;
        tmp.push_back(input);
        cout << "輸入 " << i + 1 << " 號的英文成績: ";
        cin >> input;
        tmp.push_back(input);
        cout << "輸入 " << i + 1 << " 號的數學成績: ";
        cin >> input;
        tmp.push_back(input);
        tmp.push_back(tmp[1] + tmp[2] + tmp[3]);
        tmp.push_back(tmp[4] / 3);

        table.push_back(tmp);
    }

    // for (int i = 0; i < ppl; i++) // output
    // {
    //     cout << "0平均:" << table[i][0]
    //          << " 1國文:" << table[i][1]
    //          << " 2英文:" << table[i][2]
    //          << " 3數學:" << table[i][3]
    //          << " 4總分:" << table[i][4]
    //          << " 5平均:" << table[i][5] << endl;
    // }

    while (true)
    {
        cout << "\n\n功能清單:\n";
        cout << "1:按照座號排\n";
        cout << "2:按照國文成績排\n";
        cout << "3:按照英文成績排\n";
        cout << "4:按照數學成績排\n";
        cout << "5:按照總分/平均成績排\n\n";

        cout << "6.搜尋座號\n";
        cout << "7.搜尋國文成績\n";
        cout << "8.搜尋英文成績\n";
        cout << "9.搜尋數學成績\n";
        cout << "10.搜尋總分\n";
        cout << "11.搜尋平均分數\n";
        cout << "請輸入選擇:";
        cin >> input;

        if (input < 6)
        {
            FuncSort(input, true);

        }
        else if (input < 12)
        {
            FuncSort(input, false);
            FuncSearch(input, true);
        }
        else
            cout << "function not found." << endl;
    }
}

void FuncSearch(int Func, bool Print)
{
    cout << "請輸入要搜尋的數字: ";
    cin >> searchFor;

    result.clear();
    for (int i = 0; i < ppl; i++)
    {
        if (table[i][Func - 6] == searchFor)
            result.push_back(i);
    }

    if (result.size() != 0 && Print == true) // output
    {
        cout << "\n搜尋結果: " << endl;
        cout << "座號"
             << "\t國文"
             << "\t英文"
             << "\t數學"
             << "\t總分"
             << "\t平均" << endl;

        for (auto i : result)
        {
            cout << table[i][0]
                 << "\t" << table[i][1]
                 << "\t" << table[i][2]
                 << "\t" << table[i][3]
                 << "\t" << table[i][4]
                 << "\t" << table[i][5] << endl;
        }
    }
    else if(Print == true)
        cout << "\n沒有找到任何結果" << endl;

    return;
}

void FuncSort(int Func, bool Print)
{
    int comp;
    if (Func == 1) //座號小到大
    {
        for (int i = 0; i < ppl - 1; i++)
        {
            comp = i;
            for (int j = i; j < ppl; j++)
            {
                if (table[j][Func - 1] < table[comp][Func - 1])
                    comp = j;
            }
            table[i].swap(table[comp]);
        }
    }
    else //成績大到小
    {
        for (int i = 0; i < ppl - 1; i++)
        {
            comp = i;
            for (int j = i; j < ppl; j++)
            {
                if (table[j][Func - 1] > table[comp][Func - 1])
                    comp = j;
            }
            table[i].swap(table[comp]);
        }
    }

    if(Print == true) // output
    {
        cout << "\n排序結果: " << endl;
        cout << "座號"
            << "\t國文"
            << "\t英文"
            << "\t數學"
            << "\t總分"
            << "\t平均" << endl;
        for (int i = 0; i < ppl; i++)
        {
            cout << table[i][0]
                << "\t" << table[i][1]
                << "\t" << table[i][2]
                << "\t" << table[i][3]
                << "\t" << table[i][4]
                << "\t" << table[i][5] << endl;
        }
    }

    return;
}