#include <bits/stdc++.h>
using namespace std;

void swap(int *&a, int *&b)
{
    int *tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int A = 10, B = 20;
    int *p, *q;
    p = &A;
    q = &B;
    printf("6 addr of a: %p\ta: %p\ta points to: %d\n", &p, p, *p);
    printf("7 addr of a: %p\ta: %p\ta points to: %d\n", &q, q, *q);

    swap(p, q);
    printf("8 addr of a: %p\ta: %p\ta points to: %d\n", &p, p, *p);
    printf("9 addr of a: %p\ta: %p\ta points to: %d\n", &q, q, *q);

}   