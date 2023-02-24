#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> vec[N];
int dp[N][3];
int n, m;
void dfs(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    for (auto &[v, w] : vec[u])
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
    for (auto &[v, w] : vec[u])
        if (fa != v) {
            if (w + dp[v][0] == dp[u][0])
                dp[v][2] = max(dp[u][2] + w, dp[u][1] + w);
            else
                dp[v][2] = max(dp[u][2] + w, dp[u][0] + w);
            dfs2(v, u);
        }
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        string s;
        cin >> u >> v >> w >> s;
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    dfs(1, 1);
    dfs2(1, 1);
}