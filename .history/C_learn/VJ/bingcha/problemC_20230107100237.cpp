#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int n , m , fa[100];
void INIT(){
    for(int i = 1 ; i <= m ; i++){
        fa[i] = i;
    }
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
array<int , 3> edge[10000];
int num , ans;
void kru(){
    sort(edge + 1 , edge + 1 + n);
    INIT();
    ans = 0;
    num = 0;
    for(int i = 1 ; i <= n ; i++){
        auto [w , u , v] = edge[i];
        int fu = find(u);
        int fv = find(v);
        if(fu != fv){
            num++;
            ans += w;
            merge(fu, fv);
        }
    }
}
int main(){
    while(cin >> n >> m , n != 0){
        for(int i = 1 , u , v , w ; i <= n ;i++){
            cin >> u >> v >> w;
            edge[i] = {w , u ,v};
        }
        kru();
        int cnt = 0;
        for(int i = 1 ; i <= m ; i++){
            cnt += fa[i] == i;
        }
        if(num != n - 1)cout << "?" << endl;
        else cout << ans << endl;
    }
}