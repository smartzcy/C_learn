#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    char s[10][10];
    memset(s, '.', sizeof(s));
    string str;
    cin >> str;
    cin >> str;
    while(str.find(',') != string::npos){
        string a = str.substr(0 , str.find(','));
        str = str.substr(str.find(',') + 1);
        if(a.length() == 3){
            s[abs(a[2] - '0' - 9)][a[1] - 'a' + 1] = a[0];
        }else{
            s[abs(a[1] - '0' - 9)][a[0] - 'a' + 1] = 'P';
        }
    }
    if(str.length() == 3){
        s[abs(str[2] - '0' - 9)][str[1] - 'a' + 1] = str[0];
    }else{
        s[abs(str[1] - '0' - 9)][str[0] - 'a' + 1] = 'P';
    }
    cin >> str;
    cin >> str;
    while(str.find(',') != string::npos){
        string a = str.substr(0 , str.find(','));
        str = str.substr(str.find(',') + 1);
        if(a.length() == 3){
            s[abs(a[2] - '0' - 9)][a[1] - 'a' + 1] = a[0] - 'A' + 'a';
        }else{
            s[abs(a[1] - '0' - 9)][a[0] - 'a' + 1] = 'p';
        }
    }
    if(str.length() == 3){
        s[abs(str[2] - '0' - 9)][str[1] - 'a' + 1] = str[0];
    }else{
        s[abs(str[1] - '0' - 9)][str[0] - 'a' + 1] = 'P';
    }
    cout << "+---+---+---+---+---+---+---+---+" << endl;
    for(int i = 1 ; i <= 8;i++){
        cout << '|';
        for(int j = 1 ; j <= 8;j++){
            if((i + j) % 2 == 1) cout << ':';
            else cout << '.';
            if(s[i][j] != '.') {
                cout << s[i][j];
            }else {
                if((i + j) % 2 == 1) cout << ':';
                else cout << '.';
            }
            if((i + j) % 2 == 1) cout << ':';
            else cout << '.';
            cout << "|";
        }
        cout << endl;
        cout << "+---+---+---+---+---+---+---+---+" << endl;
    }
}