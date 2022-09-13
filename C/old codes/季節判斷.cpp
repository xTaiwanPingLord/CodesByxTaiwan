#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x ;
    if(x >= 1 && x <= 3){
        cout << "spring" << endl;
    }
        if(x >= 4 && x <= 6){
        cout << "summer" << endl;
    }
        if(x >= 7 && x <= 9){
        cout << "fall" << endl;
    }
        if(x >= 10 && x <= 12){
        cout << "winter" << endl;
    }
}