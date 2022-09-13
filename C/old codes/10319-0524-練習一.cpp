#include <iostream>
using namespace ::std;

int main()
{
    int score[3] = {90, 70, 60};
    cout << score[0] << endl;
    cout << score[1] << endl;
    cout << score[2] << endl;
    score[2] = 10;
    score[1] = 70;
    cout << score[0] << endl;
    cout << score[1] << endl;
    cout << score[2] << endl;

    return 0;
}