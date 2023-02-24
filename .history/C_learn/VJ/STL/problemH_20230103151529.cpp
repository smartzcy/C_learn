#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s.length() == 1){
        if(s == "-") cout << "No";
        else cout << "Yes";
    }else if(s.length() == 2){
        if(s == "-+" || s == "+-") cout << "No";
        else cout << "Yes";
    }else{
        if(s.length() % 2 == 1) cout << "No";
        else{
            for(int i = 0 ; i < s.length() - 2 ; i++){
                string str = s.substr(i , 3);
                if(str == "+-+" || str == "-+-"){
                    cout << "No";
                    break;
                }
                if(i == s.length() - 3) cout << "Yes";
            }
        }
    }
}