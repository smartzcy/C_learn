#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1e8;
const int N = 1e3 + 5;
int n , m , q , sum = 0 , flag;
int d[N][N] , ma[N];
void floy(int x){
    for(int i = 0 ; i < n ;i++){
        if(i == x) continue;
        for(int j = 0 ; j < n; j++){
            if(i == j || j == x) continue;
            d[i][j] = min(d[i][j] , d[i][x] + d[x][j]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m >> q , n + m + q != 0){
        if (flag) cout << endl;
        flag = 1;
        for(int i = 0 ; i < n ;i++){
            d[i][i] = 0; ma[i] = 0;
            for(int j = i + 1 ; j < n ; j++){
                d[i][j] = inf;
                d[j][i] = inf;
            }
        }
        for(int i = 0 ; i < m ; i++){
            int u , v , w;
            cin >> u >> v >> w;
            d[u][v] = min(d[u][v] , w);
        }
        cout << "Case " << ++sum << ":" << endl;
        while(q--){
            int k , a , b;
            cin >> k >> a;
            if(k == 0){
                if(ma[a] == 0) {
                    ma[a] = 1;
                    floy(a);
                }else cout << "ERROR! At point " << a << endl;
            }else{
                cin >> b;
                if(ma[a] == 0 || ma[b] == 0) cout << "ERROR! At path " << a << " to " << b << endl;
                else{
                    if(d[a][b] < inf) cout << d[a][b] << endl;
                    else cout << "No such path" << endl;
                }
            }
        }
    }
}

// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int maxn = 1e3 + 5;
// const int INF = 1e8;
// int p[maxn][maxn], n, m, c, X;
// bool vis[maxn], flag;
// void init(){
//     for (int i = 0; i < n; i++){
//         vis[i] = 0;
//         for (int j = 0; j < n; j++){
//             if (i == j) p[i][j] = 0;
//             else p[i][j] = INF;
//         }
//     }
// }
// void floyed(int k){
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
// }
// int main(){
//     while (scanf("%d%d%d", &n, &m, &c) && n + m + c){
//         if (flag) cout << endl;
//         flag = 1;
//         init();
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             scanf("%d%d%d", &u, &v, &w);
//             p[u][v] = min(p[u][v], w);
//         }
//         cout << "Case " << ++X << ":" << endl;
//         while (c--)
//         {
//             int ai, bi, ci;
//             scanf("%d%d", &ai, &bi);
//             if (!ai)
//             {
//                 if (vis[bi])
//                     cout << "ERROR! At point " << bi << endl;
//                 else
//                 {
//                     vis[bi] = 1;
//                     floyed(bi);
//                 }
//             }
//             else
//             {
//                 scanf("%d", &ci);
//                 if (!vis[bi] || !vis[ci])
//                     cout << "ERROR! At path " << bi << " to " << ci << endl;
//                 else if (p[bi][ci] < INF)
//                     cout << p[bi][ci] << endl;
//                 else
//                     cout << "No such path" << endl;
//             }
//         }
//     }
//     return 0;
// }