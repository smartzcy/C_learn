#include<iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int k = str.length();
    cout << k;
    for(int i = 1 ; i < k ; i++){
        string s;
        cin >> s;
        str += s;
    }
    int num = 0;
    int sum = 0;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] - '0' == num){
            sum++;
        }else{
            cout << " " << sum;
            sum = 1;
            num = str[i] - '0';
        }
    }
    cout << " " << sum;
    return 0;
}