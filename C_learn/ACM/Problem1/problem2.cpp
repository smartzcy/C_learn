#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int cot = 0;
        for(int i = 0 ; i < str.length();i++){
            if(str[i] == 'Q'){
                cot++;
            }else if(str[i] == 'A'){
                if(cot > 0) cot--;
            }
        }
        if(cot == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}