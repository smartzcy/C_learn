#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> vec[N];
int par[N][30], val[N][30], dp[N];
int n, m;
void dfs(int u, int f) {
    dp[u] = dp[f] + 1;
    for (auto &[v, w] : vec[u]) {
        if (v == f) continue;
        par[v][0] = u;
        val[v][0] = w;
        dfs(v, u);
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
            vec[u].push_back({v, w});
            vec[v].push_back({u, w});
        }
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
        }
    }
}