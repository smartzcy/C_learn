#include <iostream>
#include<cmath>
using namespace std;
int n , m , f[10000] , d[10000];
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void INIT(){
    for(int i = 1 ; i <= n ; i++){
        f[i] = i;
    }
}
int main(){
    cin >> n >> m;
    INIT();
    for(int i = 0 ; i < m ; i++){
        int x , y;
        cin >> x >> y;
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            d[fx] += d[fy] + 1;
            f[fy] = fx;
        }
    }
    long long ans = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i == f[i]) ans *= pow(2 , d[i]);
    }
    cout << ans << endl;
}