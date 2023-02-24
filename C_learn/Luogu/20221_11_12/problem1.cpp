#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n <= 26){
        for(int i = 0 ; i < n;i++){
            cout << (char)('a' + i);
        }
    }else {
        for(int i = 0 ; i < 26 ;i++){
            cout << (char)('a' + i);
        }
        for(int i = 26 ; i < n;i++){
            cout << 'b';
        }
    }
    return 0;
}