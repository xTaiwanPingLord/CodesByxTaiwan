#include <bits/stdc++.h>
using namespace std;
// 黑桃 A 歸零
// A +1
// 2 +2
// 3 +3
// 4 迴轉 (如本來是順時針出牌改成逆時針出牌)
// 5 跳過一輪
// 6 +6
// 7 +7
// 8 +8
// 9 +9
// 10 −10
// J 跳過一輪
// Q −20
// K 加到 99
// S 是黑桃，H 是紅心，D 是方塊，C 是梅花

queue<string> card_stack;
map<char, vector<string>> player_priority, player_card;
vector<int> score;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 52; i++)
    {
        string tmp;
        cin >> tmp;
        card_stack.push(tmp);
    }
    cout << "no";
    
    for (int i = 0; i < 5; i++)
    {
        player_card['A'][i] = card_stack.front();
        card_stack.pop();
        player_card['B'][i] = card_stack.front();
        card_stack.pop();
        player_card['C'][i] = card_stack.front();
        card_stack.pop();
        player_card['D'][i] = card_stack.front();
        card_stack.pop();
    }
    cout << "yes";
}