#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int n , m , f[100000];
array<int , 3> edge[10000];
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}
int ans , num;
int kru(){
    ans = 0;
    num = 0;
    for(int i = 1 ; i <= n ;i++){
        f[i] = i;
    }
    for(int i = 1 ; i <= m ;i++){
        int w = edge[i][0];
        int u = edge[i][1];
        int v = edge[i][2];
        int fu = find(u);
        int fv = find(v);
        if(fu != fv){
            num++;
            ans += w;
            f[fu] = fv;
        }
        if(num == n - 1) break;
    }
    if(num != n - 1) return 1e7;
    else ans;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1 ; i <= m ; i++){
            int u , v , w;
            cin >> u >> v >> w;
            edge[i] = {w , u , v};
        }
        int cnt = 0;
        sort(edge + 1 , edge + m + 1);
        for(int i = 1 ; i <= m ;i++){
            int lf = find(edge[i][1]);
            int lr = find(edge[i][2]);
            if(lf != lr){
                f[lf] = f[lr];
                cnt += edge[i][0];
            }
        }
        kru();
        cout << cnt << endl;
        cout << ans << endl;
    }
}