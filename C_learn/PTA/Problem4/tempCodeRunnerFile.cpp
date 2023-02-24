#include<iostream>
#include<stdio.h>
using namespace std;
long long big(long long x , long long y){
    while(x % y != 0){
        long long k = x % y;
        x = y;
        y = k;
    }
    return y;
}
long long min(long long x , long long y){
    long long b = y;
    y = big(x , y);
    return x * b / y;
}
int main(){
    long long n;
    cin >> n;
    long long a1 , b1;
    scanf("%lld/%lld",&a1,&b1);
    for(long long i = 1 ; i < n;i++){
        long long a , b;
        scanf("%lld/%lld",&a,&b);
        long long k = min(b1 , b);
        a1 = k / b1 * a1 + k / b * a;
        b1 = k;
    }
    if(a1 / b1 != 0) cout << a1 / b1;
    if(a1 % b1 != 0){
        if(a1 / b1 != 0) cout << " ";
        a1 %= b1;
        long long k = big(a1 , b1);
        cout << a1 / k << "/" << b1 / k;
    }
    if(a1 == 0) cout << "0";
    cout << endl;
    return 0;
}