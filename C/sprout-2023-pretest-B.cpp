#include <bits/stdc++.h>
using namespace std;

int main()
{
    string temp, str2;
    temp.assign(5, ' ');
    temp[0] = '1';
    temp[1] = '2';
    str2 = "12";
    cout << (str2 == temp);
}