#include<iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    string s;
    int num = 0;
    int k = 0 , flag = 1;
    int n = 0 , m = 0;
    for(int i = 0 ; i < str.length();i++){
        if(str[i] <= '9' && str[i] >= '0' && flag == 1) s += str[i];
        else if(str[i] <= '9' && str[i]  >= '0' && flag == 0) num = num * 10 + str[i] - '0';
        if(str[i] == '-'){
            if(flag) n = -1;
            else m = -1;
        }else if(str[i] == '+'){
            if(flag) n = 1;
            else m = 1;
        }
        if(str[i] == 'E'){
            flag = 0;
        }
    }
    if(n == -1) cout << "-";
    if(num == 0) cout << s << endl;
    else{
        if(m == -1){
            cout << "0.";
            for(int i = 0 ; i < num - 1;i++) cout << "0";
            cout << s << endl;
        }else{
            if(s.length() - 1 > num){
                for(int i = 0 ; i <= num;i++){
                    cout << s[i];
                }
                cout << '.';
                for(int i = num + 1;i < s.length();i++){
                    cout << s[i];
                }
                cout << endl;
            }else{
                cout << s;
                for(int i = 0 ; i < num - s.length() + 1;i++){
                    cout << '0';
                }
                cout << endl;
            }
        }
    }
}