int ans = 0;
vector<pair<int, int>> G[N];
void dfs(int u, int fa) {
    for (auto &[v, w] : G[u])
        if (fa != v) {
            dfs(v, u);
            ans = max(ans, dp[u] + dp[v] + w);
            dp[u] = max(dp[u], dp[v] + w);
        }
}
}
