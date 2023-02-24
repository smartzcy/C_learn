#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e5 + 7;
int n, m, rt;
int par[N][20], dep[N], val[N];
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
void dfs1(int u, int fa) {
    for (auto &v : G[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        val[u] += val[v];
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        val[x]++;
        val[y]++;
        val[getLca(x, y)] -= 2;
    }
    dfs1(1, 0);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (val[i] == 0) ans += m;
        if (val[i] == 1) ans++;
    }
    cout << ans << endl;
}