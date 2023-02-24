#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> vec[N];
int par[N][30], val[N][30], dp[N];
int n, m;
void dfs(int u, int f) {
    dp[u] = dp[f] + 1;
    for (auto &[v, w] : vec[u]) {
        if (v == f) continue;
        par[v][0] = u;
        val[v][0] = w;
        dfs(v, u);
    }
}
void query(int u, int v) {
    int ans1 = 2e9, ans2 = -2e9;
    if (dp[u] > dp[v]) swap(u, v);
    int d = dp[v] - dp[u];
    for (int j = 30; j >= 0; j--)
        if (d & (1 << j)) {
            ans1 = min(val[v][j], ans1);
            ans2 = max(val[v][j], ans2);
            v = par[v][j];
        }
    if (u == v) return;
    for (int j = 30; j >= 0; j--)
        if (par[u][j] != par[v][j]) {
            ans1 = min({ans1, val[u][j], val[v][j]});
            ans2 = max({ans2, val[u][j], val[v][j]});
            u = par[u][j];
            v = par[v][j];
        }
    ans1 = min({ans1, val[u][0], val[v][0]});
    ans2 = max({ans2, val[u][0], val[u][0]});
    return;
}
int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ":" << endl;
        cin >> n;
        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            vec[u].push_back({v, w});
            vec[v].push_back({u, w});
        }
        dfs(1, 0);
        for (int j = 1; j <= 30; j++) {
            for (int u = 1; u <= n; u++) {
                par[u][j] = par[par[u][j - 1]][j - 1];
                val[u][j] = min(val[u][j - 1], val[par[u][j - 1]][j - 1]);
            }
        }
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
        }
    }
}