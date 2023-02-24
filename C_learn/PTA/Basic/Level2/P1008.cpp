#include<iostream>
using namespace std;
int main(){
    int num[100];
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n;i++){
        cin >> num[i];
    }
    m = m % n;
    for(int i = n - m;i < n;i++){
        cout << num[i] << " ";
    }
    for(int i = 0 ; i < n - m;i++){
        cout << num[i];
        if(i != n - m - 1) cout << " ";
    }
    cout << endl;
}