#include <iostream>
using namespace std;
int main(){

    int n, m;
    cin >> n >> m;

    int mat[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    for (int k = 0; (k < (n / 2)) || (k < (m / 2)); k++)
    {
        for (int i = 1; i < (n - 1); i++)
        {
            for (int j = 1; j < (m - 1); j++)
            {   
                if (
                    (mat[i][j] <= mat[i - 1][j - 1]) &&
                    (mat[i][j] <= mat[i - 1][j])     &&
                    (mat[i][j] <= mat[i - 1][j + 1]) &&

                    (mat[i][j] <= mat[i][j - 1]) &&
                    
                    (mat[i][j] <= mat[i][j + 1]) &&
            
                    (mat[i][j] <= mat[i + 1][j - 1]) &&
                    (mat[i][j] <= mat[i + 1][j])     &&
                    (mat[i][j] <= mat[i + 1][j + 1]) &&     
                    
                    (1 <= mat[i - 1][j - 1]) &&
                    (1 <= mat[i - 1][j])     &&
                    (1 <= mat[i - 1][j + 1]) &&

                    (1 <= mat[i][j - 1]) &&
                    (1 <= mat[i][j])     &&
                    (1 <= mat[i][j + 1]) &&
            
                    (1 <= mat[i + 1][j - 1]) &&
                    (1 <= mat[i + 1][j])     &&
                    (1 <= mat[i + 1][j + 1])        
                    )
                {
                    mat[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j];
            if(j < (m - 1)){
                cout << " ";
            }
        }
        cout << endl;
    }

}
