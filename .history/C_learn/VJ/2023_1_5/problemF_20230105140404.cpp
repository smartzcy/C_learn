#include <iostream>
#include<algorithm>
using namespace std;
struct People{
    int l , r;
    int cha;
    bool operator < (const People& a) const{
        return cha < a.cha;
    }
}peo[10010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n , ans = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> peo[i].l >> peo[i].r;
        peo[i].cha = peo[i].r - peo[i].l;
    }
    sort(peo + 1 , peo + n + 1);
    for(int i = 1 ; i <= n ; i++)
        ans += (i - 1) * peo[i].l + (n - i) * peo[i].r;
    cout << ans << endl;
    return 0;
}