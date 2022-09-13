#include <iostream>
#include <iomanip>
using namespace std;
    
int main(){
    int count, NumInput, Str2Num;
    string text, StrInput, proc;

    cin >> text;
    cin >> count;

    while(count >= 1){
        //cout << count << text << endl;
        
        cin >> proc >> NumInput >> StrInput;
        if(proc == "insert"){
            text.insert(NumInput, StrInput);
            //cout << NumInput << "<num  str>" << StrInput << " 輸出:" << text << endl;

        }else if(proc == "delete"){
            Str2Num = stoi(StrInput);
            text.erase(NumInput-1,Str2Num-NumInput+1);
            //cout << NumInput << "<num  str>" << Str2Num << " 輸出:" << text << endl;

        }else if(proc == "reverse"){
            int HowMany;
            Str2Num = stoi(StrInput);
            HowMany = (Str2Num - NumInput) / 2 ;
            //cout << NumInput << "到" << Str2Num << " 差多少" <<HowMany <<" 輸出:" << text << endl;
            while(HowMany !=0){
                swap(text[NumInput-1],text[Str2Num-1]);
                HowMany--;
                NumInput++;
                Str2Num--;
            }

        }
        count--;
    }
    cout << text << endl;
}