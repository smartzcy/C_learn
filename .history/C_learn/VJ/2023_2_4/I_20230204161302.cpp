// #include <iostream>
// #include <algorithm>
// #include <stack>
// #include <vector>
// using namespace std;
// const int N = 1e5;
// int n, m, t, tot, ans;
// vector<pair<int, int>> vec[N];
// int a[N];
// int dp[N];
// void dfs(int u, int ti) {
//     if (ti > t) return;
//     if (a[u] != 0) {
//         int tim = ti + min(a[u], (t - ti) / 5) * 5;
//         if (tim <= t) {
//             dp[tim] = max(dp[tim], dp[ti] + min(a[u], (t - ti) / 5));
//         }
//     }
//     for (auto [v, w] : vec[u]) {
//         dfs(v, ti + w * 2);
//     }
// }
// int main() {
//     cin >> t;
//     t--;
//     stack<pair<int, int>> s;
//     s.push({0, 1});
//     while (!s.empty()) {
//         cin >> n >> m;
//         if (m == 0) {
//             pair<int, int> p = s.top();
//             s.pop();
//             if (p.second != 1) s.push({p.first, 1});
//             vec[p.first].push_back({++tot, n});
//             s.push({tot, 2});
//         } else {
//             pair<int, int> p = s.top();
//             s.pop();
//             if (p.second != 1) s.push({p.first, 1});
//             vec[p.first].push_back({++tot, n});
//             a[tot] = m;
//         }
//     }
//     dfs(0, 0);
//     int ans = 0;
//     for (int i = 1; i <= t; i++) {
//         ans = max(ans, dp[i]);
//     }
//     cout << ans << endl;
// }

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2000;
struct node {
    int time, pic;
} seg[N << 4];
int dp[N][N];
void build(int u) {
    int n, m;
    cin >> n >> m;
    seg[u] = {n * 2, m};
    if (m == 0) {
        build(m << 1);
        build(m << 1 | 1);
    }
}
void dfs(int a, int r) {
    if (dp[a][r] || !r) return;
    if (seg[a].pic != 0) {
        dp[a][r] = min(seg[a].pic, (r - seg[a].time) / 5);
        return;
    }
    for (int i = 0; i <= r - seg[a].time; i++) {
        dfs(a << 1, i);
        dfs(a << 1 | 1, r - seg[a].time - i);
        dp[a][r] = max(dp[a][r], dp[a << 1][i] + dp[a << 1 | 1][r - seg[a].time - i]);
    }
}
inline int read() {
    int red = 0, f_f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') f_f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') red = red * 10 + ch - '0', ch = getchar();
    return red * f_f;
}
void dfs_read(int a) { // 读入基本差不多
    seg[a].time = read() * 2, seg[a].pic = read();
    // 走廊要走肯定是来回走的，所以读入时直接*2就避免后面这么多个*2了
    if (!seg[a].pic) {
        dfs_read(a << 1);
        dfs_read(a << 1 | 1);
    }
}
void dfs1(int a, int r) {
    if (dp[a][r] || !r) return;
    if (seg[a].pic) { // 已经到最里面了
        dp[a][r] = min(seg[a].pic, (r - seg[a].time) / 5);
        return;
    }
    for (int i = 0; i <= r - seg[a].time; i++) {
        dfs(a << 1, i);
        dfs(a << 1 | 1, r - seg[a].time - i);
        dp[a][r] = max(dp[a][r], dp[a << 1][i] + dp[a << 1 | 1][r - seg[a].time - i]);
    }
}
int main() {
    int t;
    cin >> t;
    t--;
    dfs_read(1);
    dfs1(1, t);
    // build(1);
    // dfs(1, t);
    cout << dp[1][t] << endl;
}