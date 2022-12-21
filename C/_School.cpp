#include <bits/stdc++.h>
using namespace std;

#define size 5

bool IsEmpty(int top)
{
    if (top < 0)
        return true;
    return false;
}

bool IsFull(int top)
{
    if (top < size - 1)
        return false;
    return true;
}

bool Push(int stack[], int *top, int value)
{
    if (!IsFull(*top))
    {
        stack[*top + 1] = value;
        *top += 1;
        return true;
    }
    return false;
}

bool Pop(int stack[], int *top)
{
    if (!IsEmpty(*top))
    {
        stack[*top] = -1;
        *top -= 1;
        return true;
    }
    return false;
}

int Top(int stack[], int *top)
{
    return stack[*top];
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int input = 0, value, top = -1;
    int stack[size];
    for (auto &i : stack)
        i = -1;

    while (input != -1)
    {
        cout << "push:1, pop:2, end:-1 \n";
        cin >> input;
        if (input == 1)
        {
            cout << "push value: \n";
            cin >> value;
            if (Push(stack, &top, value))
                cout << "pushed \n";
            else
                cout << "not pushed \n";
        }
        else if (input == 2)
        {
            if (Pop(stack, &top))
                cout << "poped \n";
            else
                cout << "not poped \n";
        }

        // for (auto i : stack)
        // {
        //     cout << i << " ";
        // }
        // cout << top << endl;
    }
}