#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5;
vector<int> vec[N];
int dp[N][2];
void dfs(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    int mx = 0;
    for (auto v : vec[u]) {
        if (fa != v) {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            mx = max(mx, dp[v][1]);
        }
    }
    dp[u][1] += mx;
}
int main() {
    int n;
    cin >> n;
    for (int i = 2, u; i <= n; i++) {
        cin >> u;
        vec[u].push_back(i);
        vec[i].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
}