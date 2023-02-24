vector<int> G[N];
int dp[N][N];
int temp_dp[N];
void dfs(int u, int fa) {
    dp[u][0] = -1e9;
    dp[u][1] = a[u];
    for (auto &v : G[u]) {
        dfs(v, u);
        for (int i = 0; i <= m + 1; i++) temp_dp[i] = dp[u][i];
        for (int i = 0; i <= m + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                temp_dp[i + j] = max(temp_dp[i + j], dp[u][i] + dp[v][j]);
            }
        }
        for (int i = 0; i <= m + 1; i++) dp[u][i] = temp_dp[i];
    }
}