#include<iostream>
using namespace std;
int main(){
    int n;
    int sum = 0;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int a , b , c;
        cin >> a >> b >> c;
        if(a + b + c >= 2) sum++;
    }
    cout << sum;
}