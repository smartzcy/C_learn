#include<iostream>
using namespace std;
int main(){
    int n , flag = 1;
    cin >> n;
    if(n < 0) flag = -1;
    n = abs(n);
    int num = 0;
    while(n != 0){
        num = num * 10 + n % 10;
        n /= 10;
    }
    cout << flag * num;
}