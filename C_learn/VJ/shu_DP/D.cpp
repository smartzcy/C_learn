#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 400;
int n, m;
vector<int> vec[N];
int dp[N][N], sz[N];
int temp_dp[N];
void dfs(int u, int fa) {
    dp[u][0] = -1e9;
    sz[u] = 1;
    for (auto &v : vec[u]) {
        dfs(v, u);
        for (int i = 0; i <= min(m, sz[u]); i++) temp_dp[i] = dp[u][i];
        for (int i = min(m, sz[u]) + 1; i <= min(m, sz[u] + sz[v]); i++) temp_dp[i] = 0;
        for (int i = 0; i <= min(m, sz[u]); i++) {
            for (int j = 0; j <= min(m - i, sz[v]); j++) {
                temp_dp[i + j] = max(temp_dp[i + j], dp[u][i] + dp[v][j]);
            }
        }
        sz[u] += sz[v];
        for (int i = 0; i <= min(m, sz[u]); i++) dp[u][i] = temp_dp[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1, k; i <= n; i++) {
        cin >> k >> dp[i][1];
        vec[k].push_back(i);
    }
    m++;
    dfs(0, 0);
    cout << dp[0][m] << endl;
}