#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9;
int d[N] , cnt[N] , vis[N];
int n , m , s;
vector<pair<int,int> > adj[N];
void dij(int st){
    for(int i = 1 ; i <= n;i++) d[i] = inf;
    d[st] = 0;
    memset(vis,0,sizeof vis);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, st});
    while (que.size()) {
        int u = que.top().second; que.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v , w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                que.push({d[v], v});
            }
        }
    }
}
int main(){
    cin >> n >> m >> s;
    for(int i = 1 ; i <= m;i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v , w});
    }
    dij(s);
    for(int i = 1 ; i <= n ; i++){
        cout << d[i] << " ";
    }
}