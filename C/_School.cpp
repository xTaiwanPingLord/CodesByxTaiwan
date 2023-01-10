#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    char name[20];
    int chi;
    int eng;
    int math;
};

void print(Student s)
{
    printf("%d, %s, %d, %d, %d\n", s.id, s.name, s.chi, s.eng, s.math);
}

void sort(Student s[], int len)
{
    int min = 0;
    Student temp;

    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i; j < len; j++)
        {
            if (s[j].chi < s[min].chi)
                min = j;
        }
        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

int main()
{
    Student s[3];

    for (int i = 0; i < 3; i++)
    {

        scanf("%d %s %d %d %d", &s[i].id, s[i].name, &s[i].chi, &s[i].eng, &s[i].math);
    }

    sort(s, 3);

    for (int i = 0; i < 3; i++)

        print(s[i]);

    return 0;
}