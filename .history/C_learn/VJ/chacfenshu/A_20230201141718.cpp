#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
const int INF = 2e9;
vector<pair<int, int>> g[N];
int par[N][31], dep[N];
int Min[N][31], Max[N][31];
int n, q;
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    for (auto &[v, x] : g[u]) {
        if (v == f) continue;
        par[v][0] = u;
        Min[v][0] = x;
        Max[v][0] = x;
        dfs(v, u);
    }
}
pair<int, int> query(int u, int v) {
    int ans1 = 1 << 30, ans2 = -1 << 30;
    if (dep[u] > dep[v]) swap(u, v);
    int d = dep[v] - dep[u];
    for (int j = 30; j >= 0; j--)
        if (d & (1 << j)) {
            ans1 = min(ans1, Min[v][j]);
            ans2 = max(ans2, Max[v][j]);
            v = par[v][j];
        }
    if (u == v) return {ans1, ans2};
    for (int j = 30; j >= 0; j--)
        if (par[u][j] != par[v][j]) {
            ans1 = min({ans1, Min[u][j], Min[v][j]});
            ans2 = max({ans2, Max[u][j], Max[v][j]});
            u = par[u][j];
            v = par[v][j];
        }
    ans1 = min({ans1, Min[u][0], Min[v][0]});
    ans2 = max({ans2, Max[u][0], Max[v][0]});
    return {ans1, ans2};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ":" << endl;
        cin >> n;
        for (int j = 0; j <= 30; j++) {
            for (int u = 0; u <= n; u++) {
                Min[u][j] = INF;
                Max[u][j] = 0;
            }
        }
        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(1, 0);
        for (int j = 1; j <= 30; j++) {
            for (int u = 1; u <= n; u++) {
                par[u][j] = par[par[u][j - 1]][j - 1];
                Min[u][j] = min(Min[u][j - 1], Min[par[u][j - 1]][j - 1]);
                Max[u][j] = max(Max[u][j - 1], Max[par[u][j - 1]][j - 1]);
            }
        }
        cin >> q;
        for (int i = 1; i <= q; i++) {
            int u, v;
            cin >> u >> v;
            pair<int, int> p = query(u, v);
            cout << p.first << " " << p.second << endl;
        }
    }
}