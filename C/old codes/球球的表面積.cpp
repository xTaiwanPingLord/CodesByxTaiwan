#include <iostream>
using namespace std;

int Area(int r){
    return (r * r * 12);
}
int main(){
    int a, b, c;
    cin >> a >> b;
    c = Area(a) + Area(b);
    cout << c << endl;
}
