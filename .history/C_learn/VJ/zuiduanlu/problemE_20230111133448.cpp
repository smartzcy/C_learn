#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1010;
const int inf = 1e9;
int n , m;
int dp[N][N];
int d[N] , vis[N];
void dij(){
    for(int i = 1 ; i <= n ; i++){
        vis[i] = 0;
    }
    for(int i = 1; i <= n ; i++) d[i] = dp[1][i];
    vis[1] = 1;
    for(int i = 1 ; i < n ; i++){
        int maxx = 0 , k;
        for(int j = 1 ; j <= n ; j++){
            if(maxx < d[j] && !vis[j]){
                maxx = d[j];
                k = j;
            }
        }
        vis[k] = 1;
        for(int j = 1 ; j <= n ;j++){
            d[j] = max(d[j] , min(d[k] , dp[k][j]));
        }
    }
}
int main(){
    int T;
    cin >> T;
    for(int k = 1 ; k <= T ;k++){
        cin >> n >> m;
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                dp[i][j] = 0;
        for(int i = 1 ; i <= m ;i++){
            int u , v , w;
            cin >> u >> v >> w;
            if(dp[u][v] < w){
                dp[u][v] = w;
                dp[v][u] = w;
            }
        }
        dij();
        cout << "Scenario #" << k << ":" << endl;
        cout << d[n] << endl;
    }
}