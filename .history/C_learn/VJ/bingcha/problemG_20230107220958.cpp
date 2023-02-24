#include<iostream>
using namespace std;
const int mod = 1e9 + 7;
int n , a[100010] , b[100010] , c[100010] , f[100010] , vis[100010] , sz[100010];
void INIT(){
    for(int i = 1 ; i <= n ; i++) f[i] = i , vis[i] = 0 , sz[i] = 0;
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        INIT();
        for(int i = 1 ; i <= n ; i++) cin >> a[i];
        for(int i = 1 ; i <= n ; i++) cin >> b[i];
        for(int i = 1 ; i <= n ; i++) cin >> c[i];
        for(int i = 1 ; i <= n ; i++) f[find(a[i])] = find(b[i]);
        for(int i = 1 ; i <= n ; i++) vis[find(c[i])] = 1;
        for(int i = 1 ; i <= n ; i++) sz[find(i)]++;
        for(int i = 1 ; i <= n ; i++){
            if(sz[find(i)] == 1) vis[find(i)] = 1;
        }
        int ans = 1;
        for(int i = 1 ; i <= n ; i++){
            if(!vis[find(i)]){
                ans = ans * 2 % mod;
                vis[find(i)] = 1;
            }
        }
        cout << ans << endl;
    }
}