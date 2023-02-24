#include <iostream>
#include<algorithm>
using namespace std;
struct People{
    int l , r;
    int cha;
    friend bool operator < (const People& a , const People& b){
        return a.cha > b.cha;
    }
}peo[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n , ans = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> peo[i].l >> peo[i].r;
        peo[i].cha = peo[i].l - peo[i].r;
    }
    sort(peo , peo + n);
    for(int i = 0 ; i < n ; i++){
        ans += i * peo[i].l + (n - i - 1) * peo[i].r;
    }
    cout << ans << endl;
}