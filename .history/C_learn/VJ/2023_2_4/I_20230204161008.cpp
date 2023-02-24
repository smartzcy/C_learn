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

// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 2000;
// struct node {
//     int time, pic;
// } seg[N << 4];
// int dp[N][N];
// void build(int u) {
//     int n, m;
//     cin >> n >> m;
//     seg[u] = {n * 2, m};
//     if (m == 0) {
//         build(m << 1);
//         build(m << 1 | 1);
//     }
// }
// void dfs(int a, int r) {
//     if (dp[a][r] || r <= 0) return;
//     if (seg[a].pic != 0) {
//         dp[a][r] = min(seg[a].pic, (r - seg[a].time) / 5);
//         return;
//     }
//     for (int i = 0; i <= r - seg[a].time; i++) {
//         dfs(a << 1, i);
//         dfs(a << 1 | 1, r - seg[a].time - i);
//         dp[a][r] = max(dp[a][r], dp[a << 1][i] + dp[a << 1 | 1][r - seg[a].time - i]);
//     }
// }
// int main() {
//     int t;
//     cin >> t;
//     t--;
//     build(1);
//     dfs(1, t);
//     cout << dp[1][t] << endl;
// }

#include <bits/stdc++.h>
using namespace std;
int t, n, m, dp[1005][605];
// dp[i][j]表示到第i个走廊，在这里(及其子树)要用j秒时间偷的最多画数
struct node {
    int tim, pic; // tim表示走廊时间，pic表示图片个数
} tr[5005];

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
    tr[a].tim = read() * 2, tr[a].pic = read();
    // 走廊要走肯定是来回走的，所以读入时直接*2就避免后面这么多个*2了
    if (!tr[a].pic) {
        dfs_read(a << 1);
        dfs_read(a << 1 | 1);
    }
}

void dfs(int a, int r) {
    if (dp[a][r] || !r) return;
    // 第一遍交WA了，就是这里写挂了，要注意不要打错，打错就凉凉了
    if (tr[a].pic) { // 已经到最里面了
        dp[a][r] = min(tr[a].pic, (r - tr[a].tim) / 5);
        // 计算到第a个走廊在这里(及他子树)要花费r秒的时间偷的做多画数
        return;
    }
    for (int i = 0; i <= r - tr[a].tim; i++) { // 枚举往左用几秒
        dfs(a << 1, i);                        // 左边用 i 秒
        dfs(a << 1 | 1, r - tr[a].tim - i);    // 右边用 r-tim-i 秒
        // 还要减去过a的走廊的时间（已经*过2了
        dp[a][r] = max(dp[a][r], dp[a << 1][i] + dp[a << 1 | 1][r - tr[a].tim - i]);
    }
}

int main() {
    memset(dp, 0, sizeof(dp));
    t = read() - 1; // 就是众所周知的坑，警察来了你还逃得走吗？
    dfs_read(1);
    dfs(1, t); // 因为没有返回值所以放外面
    printf("%d\n", dp[1][t]);
    return 0;
}