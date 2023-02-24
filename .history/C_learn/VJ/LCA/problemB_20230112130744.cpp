#include<cstdio>
#include<vector>
using namespace std;
const int N = 1000;
int n , f[N] , vis[N] , ans[N] , d[N] , vis1[N];
vector<int> vec[N];
vector<pair<int,int> > Q[N];
void INIT(){
    for(int i = 1 ; i <= n ; i++) {
        f[i] = i;
        vec[i].clear();
        Q[i].clear();
        vis1[i] = 0;
    }
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
    while(~scanf("%d",&n)){
        INIT();
        int s = 0;
        for(int i = 0 ; i < n ; i++){
            int m , nm;
            scanf("%d:(%d)" , &m , &nm);
            for(int j = 0 ; j < nm ; j++){
                int num;
                scanf("%d", &num);
                vec[m].push_back(num);
                vis1[num] = 1;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(vis1[i] == 0) {
                s = i;
                break;
            }
        }
        int m;
        scanf("%d", &m);
        printf("1\n");
        for(int i = 1 ,u , v ; i <= m ;i++){
            scanf(" (%d %d)" , &u , &v);
            Q[u].push_back({i , v});
            Q[v].push_back({i , u});
        }
        printf("1\n");
        dfs(0 , s);
        for(int i = 1 ; i <= m ; i++){
            d[ans[i]]++;
        }
        for(int i = 1 ; i <= n ; i++){
            if(d[i] > 0) printf("%d:%d\n" , i , d[i]);
        }
    }
}