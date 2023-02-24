#include<iostream>
using namespace std;
#define int long long
const int inf = 1e18;
const int maxn = 2e2 + 10;
int mp[maxn][maxn] , dis[maxn] , vis[maxn];
int m , n;
void prim(){
    for(int i = 1 ; i <= n ; i++){
        dis[i] = inf , vis[i] = 0;
    }
    for(int i = 1 ; i <= n ; i++){
        int x = 0;
        for(int j = 1 ; j <= n ; j++){
            if(!vis[j] && (x == 0 || dis[j] < dis[x])) x = j;
        }
        vis[x] = 1;

    }
}
int main(){
    while(cin >> m >> n , m != 0){
        for(int i = 1 ; i <= n ;i++){
            for(int j = 1 ; j <= m ;j++){
                mp[i][j] = inf;
            }
        }
        for(int i = 1 ; i <= n ;i++) mp[i][i] = 0;
    }
}