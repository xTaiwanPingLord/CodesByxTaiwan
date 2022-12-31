#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10

class Queue
{
public:
    int value[MAX_SIZE];
    int front, end;

    Queue()
    {
        front = 0;
        end = 0;
        for (int &i : value)
        {
            i = -1;
        }
    }

    bool IsEmpty()
    {
        if (front == end)
            return true;
        return false;
    }

    bool IsFull()
    {
        if (end == MAX_SIZE && front != 0)
            Move();
        if (end == MAX_SIZE) // 沒辦法移動了
            return true;
        return false;
    }

    bool EnQueue(int item)
    {
        if (!IsFull())
        {
            value[end] = item;
            end++;
            return true;
        }
        return false;
    }

    bool DeQueue()
    {
        if (!IsEmpty())
        {
            value[front] = -1;
            front++;
            return true;
        }
        return false;
    }

    int Front()
    {
        if (!IsEmpty())
            return value[front];
        return -1;
    }

    void Move()
    {
        int idx = 0;
        for (int i = front; i < end; i++)
        {
            value[idx] = value[i];
            value[i] = -1;
            idx++;
        }
        end -= front;
        front = 0;
    }
};

int main()
{
    int input, value;
    Queue queue1;
    do
    {
        printf("enqueue:1 dequeue:2 結束-1\n");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("enqueue value:");
            scanf("%d", &value);
            if (!queue1.EnQueue(value))
                printf("\n    reached MAX SIZE\n");
        }
        else if (input == 2)
        {
            printf("get and dequeue value:%d\n", queue1.Front());
            queue1.DeQueue();
        }
    } while (input != -1);

    printf("\nraw: \n");
    for (const int &i : queue1.value)
    {
        printf("%d, ", i);
    }
    printf("\nqueue: \n");
    for (int i = queue1.front; i < queue1.end; i++)
    {
        printf("%d, ", queue1.value[i]);
    }
}