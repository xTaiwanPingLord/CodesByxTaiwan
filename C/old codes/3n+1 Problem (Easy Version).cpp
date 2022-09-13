#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a;
    cin >> a ;
    if(a == 1){
        cout << a << endl;
    }else if(a % 2 == 0){
        cout << fixed << setprecision(0) << (a/2.0) << endl;
    }else{
        cout << fixed << setprecision(0) << (a*3+1) << endl;
    }   
}