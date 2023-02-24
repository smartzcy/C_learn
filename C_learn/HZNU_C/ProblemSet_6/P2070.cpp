#include<iostream>
using namespace std;
int ways(int n){
    for(int i = 1; i <= 1000;i++){
        int count = 0;
        for(int j = 1 ; j <= i;j++){
            if(i % j == 0)count++;
        }
        if(count == n) return i;
    }
    return -1;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << ways(n) << endl;
    }
}