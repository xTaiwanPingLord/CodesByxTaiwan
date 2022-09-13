#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
long proc(long long input){
    if(input % 2 == 0){
        return (input / 2);
    }else{
        return (input * 3 + 1);
    }   

}
int main(){
    long long a = 0;
    int count = 0;
    while(a == 0){
        cin >> a;
    }
    if(a == 1){
        a = 4;
        count++;
    }
    while(a != 1){
        a = proc(a);
        count++;
    }
    cout << fixed << setprecision(0) << count << endl;
}