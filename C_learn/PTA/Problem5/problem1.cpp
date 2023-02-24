#include<iostream>
using namespace std;
int main(){
    int n , m;
    int num[101];
    cin >> n >> m;
    m %= n;
    for(int i = 1 ; i <= n ; i++){
        cin >> num[i];
    }
    for(int i = m + 1 ;i <= n;i++){
        cout << num[i];
        if(i != n) cout << " ";
    }
    for(int i = 1 ; i <= m;i++){
        cout << " " <<num[i];
    }
}