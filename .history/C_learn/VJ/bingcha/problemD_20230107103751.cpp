#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int n , m , f[100000];
array<int , 4> edge[10000];
bool cmp(array<int , 4>&a , array<int , 4>&b){
    if(a[3] != b[3]) return a[3] > b[3];
    else return a[0] < b[0];
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}
int ans , num;
void kru(){
    sort(edge + 1 , edge + 1 + m , cmp);
    for(int i = 1 ; i <= m ; i++){
        cout << edge[i][0] << " " << edge[i][3] << endl;
    }
    for(int i = 1 ; i <= n ; i++) f[i] = i;
    ans = 0;
    num = 0;
    for(int i = 1 ; i <= m ; i++){
        int w = edge[i][0];
        int u = edge[i][1];
        int v = edge[i][2];
        int k = edge[i][3];
        int fu = find(u);
        int fv = find(v);
        if(fu != fv){
            num++;
            if(k == 0) ans += w;
            f[fu] = fv;
        }
    }
}
int main(){
    while(cin >> n , n != 0){
        m = n * (n - 1) / 2;
        for(int i = 1 , u , v , w , k ; i <= m ;i++){
            cin >> u >> v >> w >> k;
            edge[i] = {w , u , v , k};
        }
        kru();
        cout << ans << endl;
    }
}