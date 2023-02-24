// #include<iostream>
// #include<array>
// #include<algorithm>
// using namespace std;
// int n , m , f[100000];
// array<int , 4> edge[10000];
// void INIT(){
//     for(int i = 1 ; i <= n ; i++) f[i] = i;
// }
// int find(int x){
//     return f[x] == x ? x : f[x] = find(f[x]);
// }
// void merge(int x , int y){
//     int fx = find(x);
//     int fy = find(y);
//     f[fx] = fy;
// }
// int kru(int k){
//     int ans = 0;
//     int num = 0;
//     INIT();
//     for(int i = 1 ; i <= m ;i++){
//         if(i == k) continue;
//         int w = edge[i][0];
//         int u = edge[i][1];
//         int v = edge[i][2];
//         int fu = find(u);
//         int fv = find(v);
//         if(fu != fv){
//             num++;
//             ans += w;
//             f[fu] = fv;
//         }
//     }
//     if(num != n - 1) return -1;
//     else return ans;
// }
// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         cin >> n >> m;
//         for(int i = 1 ; i <= m ; i++){
//             int u , v , w;
//             cin >> u >> v >> w;
//             edge[i] = {w , u , v , 0};
//         }
//         int cnt = 0 , ans = 0, flag = 0;
//         sort(edge + 1 , edge + m + 1);
//         INIT();
//         for(int i = 1 ; i <= m ; i++){
//             int fu = find(edge[i][1]);
//             int fv = find(edge[i][2]);
//             if(fu != fv){
//                 f[fu] = fv;
//                 edge[i][3] = 1;
//                 ans += edge[i][0];
//             }
//         }
//         for(int i = 1 ; i <= m ;i++){
//             if(edge[i][3] != 0){
//                 int cnt = kru(i);
//                 if(cnt == ans){
//                     flag = 1;
//                     break;
//                 }
//             }
//         }
//         if(flag) cout << "Not Unique!" << endl;
//         else cout << ans << endl;
//     }
// }

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 107;
const long long Maxx = 1e18;
struct Edge{
    int x, y, val, flag;
} e[MAXN * MAXN];
int t, n, m, fa[MAXN];
bool cmp(Edge& x1, Edge& x2){
    return x1.val < x2.val;
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
long long kru(int k){
    long long res = 0;
    int Lfa, Rfa, cnt = 0;
    for (int i = 1; i <= m; i++){
        if (i == k)
            continue;
        Lfa = find(e[i].x);
        Rfa = find(e[i].y);
        if (Lfa != Rfa){
            res += e[i].val;
            fa[Lfa] = Rfa;
            cnt++;
        }
        if (cnt == n - 1){
            break;
        }
    }
    if (cnt != n - 1) return Maxx;
    else return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; i++){
            cin >> e[i].x >> e[i].y >> e[i].val;
            e[i].flag = 1;
        }
        long long ans = 0;
        int Lfa, Rfa;
        sort(e + 1, e + 1 + m, cmp);
        for (int i = 1; i <= m; i++){
            Lfa = find(e[i].x);
            Rfa = find(e[i].y);
            if (Lfa != Rfa){
                fa[Lfa] = Rfa;
                ans += e[i].val;
                e[i].flag = 2;
            }
        }
        long long sum = 0, f = 1;
        for (int i = 1; i <= m; i++){
            if (e[i].flag == 2){
                for (int j = 1; j <= n; j++)
                    fa[j] = j;
                sum = kru(i);
                if (sum == ans && ans != 1e18){
                    cout << "Not Unique!"
                         << "\n";
                    f = 0;
                    break;
                }
            }
        }
        if (f) cout << ans << "\n";
    }
}