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
const int inf = 1e9;
int n, m, x;
bool vis1[N], vis2[N];
int d1[N], d2[N];
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
        adj[u].push_back(make_pair(v, w));
        adj1[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= n; i++) {
        d1[i] = inf;
        d2[i] = inf;
    }
    d1[x] = 0;
    d2[x] = 0;
    for (int i = 1; i <= n; i++) {
        int u1 = 0, u2 = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis1[j] && (u1 == 0 || d1[j] < d1[u1])) u1 = j;
            if (!vis2[j] && (u2 == 0 || d2[j] < d2[u2])) u2 = j;
        }
        vis1[u1] = 1;
        vis2[u2] = 1;
        for (int i = 0; i < adj[u1].size(); i++) {
            int v = adj[u1][i].first;
            int w = adj[u1][i].second;
            d1[v] = min(d1[v], d1[u1] + w);
        }
        for (int i = 0; i < adj1[u2].size(); i++) {
            int v = adj[u2][i].first;
            int w = adj[u2][i].second;
            d2[v] = min(d2[v], d2[u2] + w);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d1[i] + d2[i]);
    }
    cout << ans << endl;
}