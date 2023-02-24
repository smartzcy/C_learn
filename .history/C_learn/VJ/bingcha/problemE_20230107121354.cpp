#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int n , m , f[100000];
int edge[10000][4];
void INIT(){
    for(int i = 1 ; i <= n ; i++) f[i] = i;
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}
int kru(int k){
    int ans = 0;
    int num = 0;
    INIT();
    for(int i = 1 ; i <= m ;i++){
        if(i == k) continue;
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
    }
    if(num != n - 1) return -1;
    else return ans;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1 ; i <= m ; i++){
            int u , v , w;
            cin >> u >> v >> w;
            edge[i] = {w , u , v , 0};
        }
        int cnt = 0 , ans = 0, flag = 0;
        sort(edge + 1 , edge + m + 1);
        INIT();
        for(int i = 1 ; i <= m ; i++){
            int fu = find(edge[i][1]);
            int fv = find(edge[i][2]);
            if(fu != fv){
                f[fu] = fv;
                edge[i][3] = 1;
                ans += edge[i][0];
            }
        }
        for(int i = 1 ; i <= m ;i++){
            if(edge[i][3] != 0){
                int cnt = kru(i);
                if(cnt == ans){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "Not Unique!" << endl;
        else cout << ans << endl;
    }
}