#include <bits/stdc++.h>
using namespace std;

queue<string> card_stack;
map<int, vector<string>> player_card;
map<int, map<string, int>> player_priority;
int current_player = 0, score = 0;
vector<bool> out(4, false);
bool direction = true;

void GetCard()
{
    player_card[current_player].push_back(card_stack.front());
    card_stack.pop();
}

void NextPlayer()
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

void Inputs()
{
    for (int i = 0; i < 52; i++)
    {
        string tmp;
        cin >> tmp;
        card_stack.push(tmp);
    }

    for (int i = 0; i < 20; i++)
    {
        GetCard();
        NextPlayer();
    }
    int tmp;
    for (int i = 0; i < 4; i++)
    {
        for (const string &n : {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"})
        {
            for (const string &c : {"S", "H", "D", "C"})
            {
                
                cin >> tmp;
                player_priority[i][c + n] = tmp;
                // cout << (c + n) << " : " << tmp << " result: " << player_priority[i][c + n] << endl;
            }
        }
    }
}

int CountScore(string _card, bool pseudo)
{
    switch (_card.back())
    {
    case 'A':
        if (_card.front() == 'S')
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

bool Finished()
{
    int tmp = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!out[i] && !player_card[i].empty())
            tmp++;
    }
    if (tmp > 1)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string the_card;

    Inputs();

    do
    {
        cout << "player: " << current_player;
        if (!out[current_player])
        {
            the_card = player_card[current_player][0];
            for (const string &card : player_card[current_player])
            {
                if (score + CountScore(card, true) <= 99 && score + CountScore(the_card, true) > 99) // 先選不會爆炸的卡
                    the_card = card;
                else if (player_priority[current_player][card] > player_priority[current_player][the_card] && score + CountScore(card, true) <= 99) // 選更好的卡
                    the_card = card;
                cout << " | " << card << " " << player_priority[current_player][card];
            }
            cout << " -> " << the_card << " org score: " << score;
            score += CountScore(the_card, false); // 加加看
            if (score < 0)
                score = 0;
            else if (score > 99)
            {
                score -= CountScore(the_card, false);
                out[current_player] = true;
            }
            else
            {
                player_card[current_player].erase(find(player_card[current_player].begin(), player_card[current_player].end(), the_card));
                if (!card_stack.empty())
                    GetCard();
            }
            cout << " after score: " << score;
        }
        cout << endl;
        NextPlayer();
    } while (Finished());

    for (int i = 0; i < 4; i++)
    {
        if (out[i] == false)
            cout << (i + 1) << " ";
    }
}