#include <bits/stdc++.h>
using namespace std;

void Inputs(queue<string> &stack, map<int, map<string, int>> &priority)
{
    string card;
    for (int i = 0; i < 52; i++) // 卡堆
    {
        cin >> card;
        stack.push(card);
    }

    int input_priority; // 順序
    for (int player = 0; player < 4; player++)
    {
        for (const string &number : {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"})
        {
            for (const string &color : {"S", "H", "D", "C"})
            {
                cin >> input_priority;
                priority[player][color + number] = input_priority;
            }
        }
    }
}

void GetOneCard(queue<string> &stack, vector<string> &the_player_card)
{
    the_player_card.push_back(stack.front()); // 抽一張卡
    stack.pop();
}

bool Stop(const vector<string> &the_player_card, const vector<bool> &alive)
{
    if (the_player_card.empty()) // 檢查玩家有卡
        return true;

    int how_many_alives = 0; // 檢查 > 1 位玩家活著
    for (const bool i : alive)
    {
        if (i)
            how_many_alives++;
    }
    if (how_many_alives <= 1)
        return true;

    return false;
}

int CountScore(const string &card, int &score, const bool &pseudo, bool &direction)
{
    switch (card.back())
    {
    case 'A':
        if (card.front() == 'S')
        {
            if (!pseudo)
                score = 0;
            return 0;
        }
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        if (!pseudo)
        {
            direction ? direction = false : direction = true;
        }
        return 0;
    case '5':
        return 0;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case '0':
        return -10;
    case 'J':
        return 0;
    case 'Q':
        return -20;
    case 'K':
        if (!pseudo)
            score = 99;
        return 0;
    }
    return 0;
}

void NextPlayer(const bool &direction, int &current_player)
{
    if (direction)
    {
        current_player < 3 ? current_player++ : current_player = 0; // 升序
    }
    else
    {
        current_player > 0 ? current_player-- : current_player = 3; // 降序
    }
}

int main()
{
    queue<string> card_stack;
    map<int, map<string, int>> player_priority;
    vector<vector<string>> player_cards(4);
    vector<bool> player_alive(4, true);
    int current_player, score = 0, priority_value;
    bool direction = true;
    string the_card;

    Inputs(card_stack, player_priority);

    for (int i = 0; i < 5; i++) // 一個人發5張卡
    {
        for (current_player = 0; current_player < 4; current_player++)
            GetOneCard(card_stack, player_cards[current_player]);
    }
    current_player = 0;

    while (!Stop(player_cards[current_player], player_alive))
    {
        if (player_alive[current_player])
        {
            cout << "player: " << current_player;
            the_card = "";
            priority_value = 0;
            for (const string &card : player_cards[current_player])
            {
                cout << " | " << card << " " << player_priority[current_player][card];
                if (score + CountScore(card, score, true, direction) > 99) // 不能出
                    continue;
                else if (player_priority[current_player][card] > priority_value) // 能出，且找到更高優先度的卡
                {
                    priority_value = player_priority[current_player][card];
                    the_card = card;
                }
            }

            if (the_card != "") // 有任何一張卡 -> 算分 + 抽卡
            {
                cout << " -> " << the_card << " org score: " << score;
                score += CountScore(the_card, score, false, direction);
                player_cards[current_player].erase(find(player_cards[current_player].begin(), player_cards[current_player].end(), the_card));
                if (score < 0)
                    score = 0;
                if (!card_stack.empty())
                    GetOneCard(card_stack, player_cards[current_player]);
                cout << " now score: " << score << endl;
            }
            else // 沒有卡 -> 淘汰
            {
                player_alive[current_player] = false;
                cout << "out" << endl;
            }
        }
        NextPlayer(direction, current_player); // 下一位
    }

    for (int i = 0; i < 4; i++)
    {
        if (player_alive[i])
            cout << (i + 1) << " ";
        ;
    }
}