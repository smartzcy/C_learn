#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num[101];
    for(int i = 1 ; i <= n - 1 ;i++){
        cin >> num[i];
    }
    int a , b , sum = 0;
    cin >> a >> b;
    for(int i = a ; i <= b - 1;i++){
        sum += num[i];
    }
    cout << sum;
}