int ans = 0;
vector<int> G[N];
int sz[N], maxx[N], ans = 2e9, ansu;
void dfs(int u, int fa) {
    sz[u] = 1;
    maxx[u] = 0;
    for (auto &v : G[u])
        if (fa != v) {
            dfs(v, u);
            sz[u] += sz[v];
            maxx[u] = max(maxx[u], sz[v]);
        }
    maxx[u] = max(maxx[u], n - sz[u]);
    if (maxx[u] < ans) ans = maxx[u], ansu = u;
}
