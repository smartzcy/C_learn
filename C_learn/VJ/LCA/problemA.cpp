// #include <iostream>
// #include <vector>
// using namespace std;
// const int N = 5e5 + 10;
// vector<int> vec[N];
// vector<pair<int, int>> Q[N];
// int f[N], vis[N], ans[N];
// int n, m, s;
// void INIT() {
//     for (int i = 1; i <= n; i++) f[i] = i;
// }
// int find(int x) {
//     return f[x] == x ? x : f[x] = find(f[x]);
// }
// void merge(int x, int y) {
//     int xx = find(x);
//     int yy = find(y);
//     if (xx == yy) return;
//     f[yy] = xx;
// }
// void dfs(int u, int fa) {
//     vis[u] = 1;
//     for (auto [qid, v] : Q[u]) {
//         if (!vis[v]) continue;
//         ans[qid] = find(v);
//     }
//     for (auto v : vec[u]) {
//         if (v == fa) continue;
//         dfs(v, u);
//         merge(u, v);
//     }
// }
// int main() {
//     cin >> n >> m >> s;
//     INIT();
//     for (int i = 1, u, v; i < n; i++) {
//         cin >> u >> v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);
//     }
//     for (int i = 1, u, v; i <= m; i++) {
//         cin >> u >> v;
//         Q[u].push_back({i, v});
//         Q[v].push_back({i, u});
//     }
//     dfs(s, 0);
//     for (int i = 1; i <= m; i++) {
//         cout << ans[i] << endl;
//     }
// }

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
int n, m, rt;
int par[N][20], dep[N];
vector<int> G[N];
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    par[u][0] = fa;
    for (int i = 1; i < 20; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto &v : G[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int getLca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (dep[par[u][i]] >= dep[v]) u = par[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i], v = par[v][i];
        }
    }
    return par[u][0];
}
void solve() {
    cin >> n >> m >> rt;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(rt, 0);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        cout << getLca(u, v) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int t = 1;
    while (t--) solve();
    return 0;
}