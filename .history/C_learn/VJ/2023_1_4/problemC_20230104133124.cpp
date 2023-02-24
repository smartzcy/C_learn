#include<iostream>
#include<cmath>
using namespace std;
long long qpow(long long a , long long b , long long p){
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long a1 , a2 , a3 , k;
        cin >> a1 >> a2 >> a3 >> k;
        if(a3 - a2 == a2 - a1) cout << ((k - 1) * (a2 - a1) + a1) % 200907 << endl;
        else cout << (a1 * pow(a3 / a2 , k - 1)) % 200907 << endl;
    }
}