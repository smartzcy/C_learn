#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str = "ROYGBIV";
    if(n <= 7){
        for(int i = 0 ; i < n;i++) cout << str[i];
    }else{
        cout << str;
        for(int i = 0 ; i < n - 7;i++){
            cout << str[3 + i % 4];
        }
    }
}