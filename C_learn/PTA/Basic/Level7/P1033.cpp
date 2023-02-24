#include<iostream>
#include<string>
using namespace std;
int main(){
    string str , s;
    getline(cin,str);
    int flag = 0;
    if(str.find('+') != string::npos) flag = 1;
    cin >> s;
    for(int i = 0 ; i < s.length();i++){
        if(s[i] <= '9' && s[i] >= '0') {
            if(str.find(s[i]) == string::npos) {
                cout << s[i];
            }
        }else if(s[i] <= 'z' && s[i] >= 'a') {
            char ch = s[i] - 'a' + 'A';
            if(str.find(ch) == string::npos) cout << s[i];
        }else if(s[i] <= 'Z' && s[i] >= 'A'){
            if(flag == 0 && str.find(s[i]) == string::npos) cout << s[i];
        }else if(str.find(s[i]) == string::npos) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}