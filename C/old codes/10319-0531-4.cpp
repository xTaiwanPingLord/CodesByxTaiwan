#include <stdio.h>
#include <stdlib.h>
int main()
{
    int table[10] = {0}; //預設0為空位1為已訂 ，注意初始值放在迴圈外避免重複定義
    //[0 1 0 0 0 0 0 1 0 0] 表示2.8桌有訂位
    int table_num, people; //桌號與人數
    while (true)
    {
        printf("座位狀況:\n");
        for (int i = 0; i < 10; i++)
        { //顯示當前位子狀態
            if (table[i] == 0)
            {
                printf(" [ 空位 ] ");
            }
            else
            {
                printf(" [ 已訂 ] ");
            }
        }
        printf("\n請輸入訂位需求\n");
        printf("桌號:");
        scanf("%d", &table_num); //使用者輸入桌號1-10但索引是0-9 所以等下請用table[table_num-1]呼叫
        printf("人數:");
        scanf("%d", &people);
        if (table[table_num - 1] == 0 && people <= 4) //該座位為空位且少於等於4人
        {
            table[table_num - 1] = 1;
            printf("%d 桌已訂位!", table_num);
        }
        else if (table[table_num - 1] == 0 && people > 4) //該座位為空位且多於4人則顯示請分桌
        {
            printf("請分桌!");
        }
        else //該座位為已訂位則顯示請查看其他桌
        {
            printf("請查看其他桌!");
        }
        system("pause");
        system("cls");
    }
}