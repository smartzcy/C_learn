#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s.length() % 2 == 1) cout << "No";
    else{
        int sum = 0 , flag = 1;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '-'){
                if(sum % 2 == 1) {
                    flag = 0;
                    break;
                }
                sum = 0;
            }else if(s[i] == '+') sum++;
        }
        if(flag) cout << "Yes";
        else cout << "No";
    }
}