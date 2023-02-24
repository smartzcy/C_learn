// #include <iostream>
// #include <cstring>
// using namespace std;
// typedef long long ll;
// const int N = 1e6 + 10;
// const int mod1 = 3145739;
// const int mod2 = 6291469;
// struct Hash {
//     ll has1[N], has2[N];
//     ll bas1[N], bas2[N];
//     ll p1, p2;
//     void init(char s[]) {
//         p1 = 2333;
//         p2 = 17;
//         has1[0] = has2[0] = 0;
//         bas1[0] = bas2[0] = 1;
//         int len = strlen(s + 1);
//         for (int i = 1; i <= len; ++i) {
//             bas1[i] = (bas1[i - 1] * p1) % mod1;
//             bas2[i] = (bas2[i - 1] * p2) % mod2;
//         }
//         for (int i = 1; i <= len; ++i) {
//             has1[i] = (has1[i - 1] * p1 + s[i]) % mod1;
//             has2[i] = (has2[i - 1] * p2 + s[i]) % mod2;
//         }
//     }
//     ll gethash1(int r, int len) {
//         return ((has1[r] - has1[r - len] * bas1[len]) % mod1 + mod1) % mod1;
//     }
//     ll gethash2(int r, int len) {
//         return ((has2[r] - has2[r - len] * bas2[len]) % mod2 + mod2) % mod2;
//     }
// };
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
const int INF = 2e9;
vector<pair<int, int>> g[N];
int par[N][31], val[N][31], dep[N];
int Min[N][31], Max[N][31];
int n, m, q;
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    for (auto &[v, x] : g[u]) {
        if (v == f) continue;
        // 处理往上一个点的情况
        par[v][0] = u;
        val[v][0] = x;
        dfs(v, u);
    }
}
// 在求解lca的过程中额外维护我们要的信息
int query(int u, int v) {
    int ans = 1 << 30;
    if (dep[u] > dep[v]) swap(u, v);
    int d = dep[v] - dep[u];
    for (int j = 30; j >= 0; j--)
        if (d & (1 << j)) {
            ans = min(ans, val[v][j]);
            v = par[v][j];
        }
    if (u == v) return ans;
    for (int j = 30; j >= 0; j--)
        if (par[u][j] != par[v][j]) {
            ans = min({ans, val[u][j], val[v][j]});
            u = par[u][j];
            v = par[v][j];
        }
    ans = min({ans, val[u][0], val[v][0]});
    return ans;
}
int main() {
    cin >> n;
    for (int j = 0; j <= 30; j++) {
        for (int u = 0; u <= n; u++) {
            val[u][j] = INF;
        }
    }
    for (int i = 1, u, v, w; i < n; i++) {
        // u 到 v 的权值为 w 的边
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    for (int j = 1; j <= 30; j++) {
        for (int u = 1; u <= n; u++) {
            par[u][j] = par[par[u][j - 1]][j - 1];
            val[u][j] = min(val[u][j - 1], val[par[u][j - 1]][j - 1]);
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }
}