#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
vector<int> G[N];
int dp[N][N], sz[N];
int temp_dp[N];
void dfs(int u, int fa) {
    dp[u][0] = -1e9;
    dp[u][1] = a[u];
    sz[u] = 1;
    for (auto &v : G[u]) {
        dfs(v, u);
        for (int i = 0; i <= min(m + 1, sz[u]); i++) temp_dp[i] = dp[u][i];
        for (int i = min(m + 1, sz[u]) + 1; i <= min(m + 1, sz[u] + sz[v]); i++) temp_dp[i] = 0;
        for (int i = 0; i <= min(m + 1, sz[u]); i++) {
            for (int j = 0; j <= min(m + 1 - i, sz[v]); j++) {
                temp_dp[i + j] = max(temp_dp[i + j], dp[u][i] + dp[v][j]);
            }
        }
        sz[u] += sz[v];
        for (int i = 0; i <= min(m + 1, sz[u]); i++) dp[u][i] = temp_dp[i];
    }
}
int main() {
}