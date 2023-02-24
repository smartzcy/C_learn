// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int N = 1e5;
// vector<pair<int, int>> vec[N];
// int par[N][30], val[N][30], dp[N];
// int n, m;
// int ans1 = 2e9, ans2 = -2e9;
// void dfs(int u, int f) {
//     dp[u] = dp[f] + 1;
//     for (auto &[v, w] : vec[u]) {
//         if (v == f) continue;
//         par[v][0] = u;
//         val[v][0] = w;
//         dfs(v, u);
//     }
// }
// void query(int u, int v) {
//     if (dp[u] > dp[v]) swap(u, v);
//     int d = dp[v] - dp[u];
//     for (int j = 30; j >= 0; j--)
//         if (d & (1 << j)) {
//             ans1 = min(val[v][j], ans1);
//             ans2 = max(val[v][j], ans2);
//             v = par[v][j];
//         }
//     if (u == v) return;
//     for (int j = 30; j >= 0; j--)
//         if (par[u][j] != par[v][j]) {
//             ans1 = min({ans1, val[u][j], val[v][j]});
//             ans2 = max({ans2, val[u][j], val[v][j]});
//             u = par[u][j];
//             v = par[v][j];
//         }
//     ans1 = min({ans1, val[u][0], val[v][0]});
//     ans2 = max({ans2, val[u][0], val[u][0]});
//     return;
// }
// int main() {
//     int T;
//     cin >> T;
//     for (int k = 1; k <= T; k++) {
//         cout << "Case " << k << ":" << endl;
//         cin >> n;
//         for (int i = 1, u, v, w; i < n; i++) {
//             cin >> u >> v >> w;
//             vec[u].push_back({v, w});
//             vec[v].push_back({u, w});
//         }
//         dfs(1, 0);
//         for (int j = 1; j <= 30; j++) {
//             for (int u = 1; u <= n; u++) {
//                 par[u][j] = par[par[u][j - 1]][j - 1];
//                 val[u][j] = min(val[u][j - 1], val[par[u][j - 1]][j - 1]);
//             }
//         }
//         cin >> m;
//         while (m--) {
//             ans1 = 2e9;
//             ans2 = -2e9;
//             int x, y;
//             cin >> x >> y;
//             query(x, y);
//             cout << ans1 << " " << ans2 << endl;
//         }
//     }
// }

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
            1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 总结：
                只要信息可以在倍增过程中 快速合并。并且问题中 不带修改，我们都可以使用倍增来快速询问一些关于
                    树上路径 的信息。
                        树上差分
                            点差分
                                我们来看这样一个例子：
                                    给定一棵 个点的树，每个点初始点权都是 。你要执行 次操作，每次操作形如：
                                        表示对 到 路径上的所有点点权都增加 。 在 次操作之后，你需要输出所有点的点权。
                                            是否有一点点熟悉的味道？它是不是很像这样一个题目：
                                                给定一个长度为 的数组 。你要执行 次操作，每次操作形如：
                                                    表示对区间 的每个数增加 。
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
    cin >> n >> q;
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
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }
}