#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
vector<int> vec[N];
int dp[N][20], deep[N], nm, a[N];
long long n, m, k, max_dep;
void dfs(int u, int fa, int dep) {
    deep[u] = dep;
    dp[u][0] = fa;
    for (int i = 1; i <= nm; i++) {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto v : vec[u]) {
        if (v != fa) {
            dfs(v, u, dep + 1);
        }
    }
}
int LCA(int x, int y) {
    if (deep[x] < deep[y]) {
        swap(x, y);
    }
    for (int i = nm; i >= 0; i--) {
        if (deep[x] - deep[y] >= (1 << i)) {
            x = dp[x][i];
        }
    }
    if (x == y) return x;
    for (int i = nm; i >= 0; i--) {
        if (dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}
bool solve() {
    for (int i = 1; i <= k; i++) {
        int lca = LCA(a[i], max_dep);
        if (lca != a[i] && lca != dp[a[i]][0]) return false;
    }
    return true;
}
int main() {
    cin >> n >> m;
    nm = log2(n) + 1;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 0, 0);
    while (m--) {
        cin >> k;
        max_dep = 0;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            if (max_dep == 0 || deep[max_dep] < deep[a[i]]) {
                max_dep = a[i];
            }
        }
        if (solve()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}