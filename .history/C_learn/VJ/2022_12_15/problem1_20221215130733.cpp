#include<iostream>
using namespace std;
int main(){
    int n;
    int sum = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
    }
    if(n % 2 == 1){
        n = (n - 1) / 2;
        sum = n / 2 + n % 2;
        sum *= 2;
    }else{
        n = n / 2;
        sum = n / 2 + n % 2;
        sum = sum * 2 + 1;
    }
    cout << sum;
}