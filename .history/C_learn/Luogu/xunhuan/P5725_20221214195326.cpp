#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        for(int j = 1 ; j <= n;j++){
            if(i * n + j < 10){
                cout << "0";
            }
            cout << i * n + j;
        }
        cout << endl;
    }
    int k = 1;
    for(int i = 1 ; i <= n; i++){
        for(int j = 0 ; j < n - i;j++){
            cout << " ";
        }
        for(int j = 0 ; j < i;j++){
            if(k < 10) cout << "0";
            cout << k++ << endl;
        }
        cout << endl;
    }
}