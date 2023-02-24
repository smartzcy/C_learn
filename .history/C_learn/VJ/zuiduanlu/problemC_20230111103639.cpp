#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 110;
const int inf = 1e9;
int d[N][N];
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n;i++)
        for(int j = 1 ; j <= n ;j++)
            d[i][j] = inf;
    for(int i = 0 ; i < m;i++){
        int u , v , w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for(int k = 1 ; k <= n ;k++)
        for(int u = 1 ; u <= n; u++)
            for(int v = 1 ; v <= n; v++)
                d[u][v] = min(d[u][v] , d[u][v] + d[k][v]);
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j) cout << 0 << " ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
}