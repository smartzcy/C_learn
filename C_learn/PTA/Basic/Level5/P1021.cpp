#include<iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int num[10] = {0};
    for(int i = 0 ; i < str.length();i++){
        num[str[i] - '0']++;
    }
    for(int i = 0 ; i < 10;i++){
        if(num[i] != 0) cout << i << ":" << num[i] << endl;
    }
}