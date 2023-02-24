// #include <iostream>
// #include <cstdlib>
// #include <algorithm>
// using namespace std;
// const int N = 1e3 + 10;
// const int inf = 1e9;
// long long d[N][N];
// int n, m, x;
// int main() {
//     scanf("%d %d %d", &n, &m, &x);
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             if (i == j)
//                 d[i][j] = 0;
//             else
//                 d[i][j] = inf;
//     while (m--) {
//         int u, v, w;
//         scanf("%d %d %d", &u, &v, &w);
//         d[u][v] = w;
//     }
//     for (int k = 1; k <= n; k++)
//         for (int u = 1; u <= n; u++)
//             if (d[u][k] == inf)
//                 continue;
//             else
//                 for (int v = 1; v <= n; v++)
//                     d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
//     long long ans = 0;
//     for (int i = 1; i <= n; i++) {
//         ans = max(ans, d[i][x] + d[x][i]);
//     }
//     printf("%lld", ans);
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e3 + 10;
int n, m, x;
bool vis[N];
int d[N];
vector<pair<int, int>> adj[N];
vector<pair<int, int>> adj1[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj1[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        int u = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (u == 0 || d[j] < d[u])) u = j;
        }
        vis[u] = 1;
        for (auto [v, w] : adj[u]) {
            d[v] = min(d[v], d[u] + w);
        }
    }
}