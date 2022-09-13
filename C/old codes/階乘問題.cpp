#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a = 1;
    long long b = 1;
    cin >> a ;
    while( a != 1 ){
        b = b * a;
        a--;
    }
    cout << fixed << setprecision(0) << b << endl;

}