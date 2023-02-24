#include<iostream>
using namespace std;
int main(){
    string str1 , str2;
    cin >> str1 >> str2;
    int num[36] = {0};
    for(int i = 0 ; i < str2.length();i++){
        if(str2[i] <= '9' && str2[i] >= '0') num[str2[i] - '0'] = 1;
        else if(str2[i] <= 'z' && str2[i] >= 'a') num[str2[i] - 'a' + 10] = 1;
        else if(str2[i] <= 'Z' && str2[i] >= 'A') num[str2[i] - 'A' + 10] = 1;
    }
    for(int i = 0 ; i < str1.length();i++){
        if(str1[i] <= '9' && str1[i] >= '0' && num[str1[i] - '0'] == 0){
            cout << str1[i];
            num[str1[i] - '0'] = 1;
        }else if(str1[i] <= 'z' && str1[i] >= 'a' && num[str1[i] - 'a' + 10] == 0){
            char ch = str1[i] - 'a' + 'A';
            cout << ch;
            num[str1[i] - 'a' + 10] = 1;
        }else if(str1[i] <= 'Z' && str1[i] >= 'A' && num[str1[i] - 'A' + 10] == 0){
            cout << str1[i];
            num[str1[i] - 'A' + 10] = 1;
        }
    }
    cout << endl;
    return 0;
}