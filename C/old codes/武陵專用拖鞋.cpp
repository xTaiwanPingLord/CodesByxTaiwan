#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main(){
    long long total, a, b, c, org, coupon; //拖鞋總數 一打 半打 一雙 原價 折價券
    int A, B, C, COUPON;
    long long price = 0;//折後價
    cin >> total;
    a = total / 12;
    A = a;
    total = total - 12 * a;
    b = total / 6;
    B = b;
    total = total - 6 * b;
    c = total;
    C = c;
    org = a*2800 + b*1500 + c*300;
    coupon = org / 500;
    coupon = coupon / 5;
    COUPON = coupon;
    while(a != 0 && coupon != 0){
        price = price + 2520;
        coupon--;
        a--;
    }
    while(b != 0 && coupon != 0){
        price = price + 1350;
        coupon--;
        b--;
    }
    while(c != 0 && coupon != 0){
        price = price + 270;
        coupon--;
        c--;
    }
    price = price + a * 2800 + b * 1500 + c * 300;
    cout << "打數:" << A << "\t半打:" << B << "\t雙:" << C << "\t折價卷:" << COUPON << "\t原價" << org << endl;
    cout << "打數使用:" << (A-a) << "\t半打:" << (B - b) << "\t雙:" << (C - c)  << "\t折價卷:" << (coupon) << endl;
    cout << fixed << setprecision(0) << price << endl;

}