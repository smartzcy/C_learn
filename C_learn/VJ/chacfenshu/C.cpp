#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
int n, m, rt;
int par[N][20], dep[N], cnt[N], val[N], qaq[N], ans[N];
vector<int> g[N];
pair<int, int> G[N];
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    par[u][0] = fa;
    for (int i = 1; i < 20; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto &v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int LCA(int u, int v) {
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
void dfs1(int u, int fa) {
    val[u] = cnt[u];
    for (auto &v : g[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        val[u] += val[v];
    }
    ans[qaq[u]] = val[u];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        G[i] = {u, v};
    }
    dfs(1, 0);
    for (int i = 1; i < n; i++) {
        int u = G[i].first;
        int v = G[i].second;
        if (dep[u] < dep[v]) swap(u, v);
        qaq[u] = i;
    }
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y]++;
        cnt[LCA(x, y)] -= 2;
    }
    dfs1(1, 0);
    for (int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
}