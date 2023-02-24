#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> vec[N];
int dp[N][3];
int n;
void dfs(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i].first, w = vec[u][i].second;
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
}
void dfs2(int u, int fa) {
    for (int i = 0; i < vec[u].size(); i++) {
        int v = vec[u][i].first, w = vec[u][i].second;
        if (fa != v) {
            if (w + dp[v][0] == dp[u][0])
                dp[v][2] = max(dp[u][2] + w, dp[u][1] + w);
            else
                dp[v][2] = max(dp[u][2] + w, dp[u][0] + w);
            dfs2(v, u);
        }
    }
}
int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ":" << endl;
        cin >> n;
        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            vec[u + 1].push_back({v + 1, w});
            vec[v + 1].push_back({u + 1, w});
        }
        dfs(1, 1);
        dfs2(3, 3);
        for (int i = 1; i <= n; i++) {
            cout << dp[i][2] << endl;
        }
    }
}