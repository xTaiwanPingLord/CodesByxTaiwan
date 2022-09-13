#include <iostream>
#include <iomanip>
using namespace std;
    
int main(){
    long long calcCount, r1, c1, r2, c2, row ,col;
    cin >> calcCount;

    
    for (long long count = 0; count < calcCount; count++){
        cin >> r1 >> c1 >> r2 >> c2;
        long long m1[c1][r2], m2[c2][r2];

        if((r1 != c2) && (r2 != c1)){
            cout << "No def." << endl;
        }else{
            if(r1 > c1){
                row = r1;
                col = r1;
            }else{
                row = r2;
                col = r2;
            }
            long long mul[row][col];

            //input
            for(long long i = 0; i < c1; i++){
                for (long long j = 0; j < r1; j++)
                {
                    cin >> m1[i][j];
                }
            }
        
            for(long long i = 0; i < c2; i++){
                for(long long j = 0; j < r2; j++)
                {
                    cin >> m2[i][j];
                }
            }


            //multiply
            for(long long i = 0; i < col; i++){
                for(long long j = 0; j < row; j++){
                    mul[i][j] = 0;
                    for (long long k = 0; k < col; k++){
                        mul[i][j] += m1[i][k] * m2[k][j];
                        cout << "m1 m2 mul " << m1[i][k] << " " << m2[k][j] << " " << mul[i][j] << endl;
                    }
                }
            }

            //output
            for(long long i = 0; i < col; i++){
                for(long long j = 0; j < row; j++){
                    cout << mul[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
    return 0;
}