#include <iostream>
using namespace std;

int main(){
    long long n;
    int score[10000], scoreOut[10000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> score[i];
        //cout << "score: " << score[i] << endl;
        if(score[i] < 0){
            scoreOut[n - i -1] = score[i];
            //cout << "true " << endl;

        }else{
            scoreOut[n - i - 1] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        cout << scoreOut[i] <<endl;
    }
}