vector<pair<int, int>> G[N];
int dp[N][3];
void dfs(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    for (auto &[v, w] : G[u])
        if (fa != v) {
            dfs(v, u);
            if (dp[v][0] + w >= dp[u][0]) {
                dp[u][1] = dp[u][0];
                dp[u][0] = dp[v][0] + w;
            } else if (dp[v][0] + w >= dp[u][1]) {
                dp[u][1] = dp[v][0] + w;
            }
        }
}
void dfs2(int u, int fa) {
    for (auto &[v, w] : G[u])
        if (fa != v) {
            if (w + dp[v][0] == dp[u][0])
                dp[v][2] = max(dp[u][2] + w, dp[u][1] + w);
            else
                dp[v][2] = max(dp[u][2] + w, dp[u][0] + w);
            dfs2(v, u);
        }
}