#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e8;
int d[N] , cnt[N] , vis[N];
int n , m , s;
vector<pair<int,int> > adj[N];
bool spfa(int st){
    memset(cnt , 0 , sizeof cnt);
    for(int i = 1 ; i <= n;i++) d[i] = inf;
    d[st] = 0;
    queue<int> que;
    que.push(st);
    memset(vis,0,sizeof vis);
    vis[st] = 1;
    while(!que.empty()){
        int u = que.front(); que.pop();
        vis[u] = 0;
        for(auto [v , w] : adj[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) return true;
                if(!vis[v]){
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> m >> s;
    for(int i = 1 ; i <= m;i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v , w});
    }
    // for(int i = 1 ; i <= n ; i++){
    //     if(i == s) d[i] = 0;
    //     else d[i] = inf;
    // }
    // for(int i = 1 ; i < n ; i++){
    //     for(int j = 1 ; j <= n ; j++){
    //         for(int k = 0 ; k < adj[j].size() ; k++){
    //             int v = adj[j][k].first , w = adj[j][k].second;
    //             if(d[v] > d[j] + w) d[v] = d[j] + w;
    //         }
    //     }
    // }
    spfa(s);
    for(int i = 1 ; i <= n ; i++){
        cout << d[i] << " ";
    }
}