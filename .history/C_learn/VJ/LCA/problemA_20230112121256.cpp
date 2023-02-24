#include<iostream>
#include<vector>
using namespace std;
const int N = 5e5 + 10;
vector<int> vec[N];
vector<pair<int, int> > Q[N];
int f[N] , vis[N] , ans[N];
int n , m , s;
void INIT(){
    for(int i = 1 ; i <= n ; i++) f[i] = i;
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x , int y){
    int xx = find(x);
    int yy = find(y);
    if(xx == yy) return;
    f[yy] = xx;
}
void dfs(int u , int fa){
    vis[u] = 1;
    for(auto [qid , v] : Q[u]){
        if(!vis[v]) continue;
        ans[qid] = find(v);
    }
    for(auto v : vec[u]){
        if(v == fa) continue;
        dfs(v , u);
        merge(u , v);
    }
}
int main(){
    cin >> n >> m >> s;
    INIT();
    for(int i = 1 , u , v ; i < n ; i++){
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i = 1 , u , v ; i <= m ; i++){
        cin >> u >> v;
        Q[u].push_back({i , v});
        Q[v].push_back({i , u});
    }
    dfs(s , 0);
    for(int i = 1 ; i <= m ;i++){
        cout << ans[i] << endl;
    }
}