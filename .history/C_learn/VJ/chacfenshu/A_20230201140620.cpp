#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
const int INF = 2e9;
vector<pair<int, int>> vec[N];
int par[N][31], val[N][31], dep[N];
int Min[N][31], Max[N][31];
int n, m, q;
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    for (auto &[v, w] : vec[u]) {
        if (v == f) continue;
        par[v][0] = u;
        Min[v][0] = w;
        Max[v][0] = w;
        dfs(v, u);
    }
}
pair<int, int> query(int u, int v) {
    int ans1 = INF, ans2 = 0;
    if (dep[u] < dep[v]) swap(u, v);
    int d = 0;
    for (; 1 << d <= dep[u]; d++)
        ;
    d--;
    for (int j = d; j >= 0; j--)
        if (dep[j] - (1 << j) >= dep[v]) {
            ans1 = min(Min[v][j], ans1);
            ans2 = max(Max[v][j], ans2);
            v = par[u][j];
        }
    if (u == v) return {ans1, ans2};
    for (int j = d; j >= 0; j--)
        if (par[u][j] != par[v][j]) {
            ans1 = min({ans1, Min[u][j], Min[v][j]});
            ans2 = max({ans2, Max[u][j], Max[v][j]});
            u = par[u][j];
            v = par[v][j];
        }
    ans1 = min({ans1, Min[u][0], Min[v][0]});
    ans2 = max({ans2, Max[u][0], Max[v][0]});
    return {ans1, ans2};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ":" << endl;
        cin >> n;
        for (int i = 0; i <= n; i++) {
            vec[i].clear();
            for (int j = 0; j <= 30; j++) {
                Min[i][j] = 1e9;
                Max[i][j] = 0;
            }
        }
        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            vec[u].push_back({v, w});
            vec[v].push_back({u, w});
        }
        dfs(1, 0);
        for (int j = 1; j <= 30; j++) {
            for (int u = 1; u <= n; u++) {
                par[u][j] = par[par[u][j - 1]][j - 1];
                Min[u][j] = min(Min[u][j - 1], Min[par[u][j - 1]][j - 1]);
                Max[u][j] = max(Max[u][j - 1], Max[par[u][j - 1]][j - 1]);
            }
        }
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            pair<int, int> p = query(x, y);
            cout << p.first << " " << p.second << endl;
        }
    }
}

// #include <cstdio>
// #include <algorithm>
// #include <string.h>
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// using namespace std;
// const int INF = 0x3f3f3f3f;
// const int maxn = 2e5 + 5;
// struct Edge {
//     int v, c, nxt;
// } edge[maxn * 2];
// int top[maxn], f[maxn], deep[maxn], num[maxn], p[maxn], fp[maxn], son[maxn];
// int d[maxn], head[maxn], Min[maxn << 2], Max[maxn << 2], tot, totp;
// void add(int u, int v, int c) {
//     edge[tot].v = v;
//     edge[tot].c = c;
//     edge[tot].nxt = head[u];
//     head[u] = tot++;
// }
// int dfs1(int u, int fa, int cnt) {
//     f[u] = fa;
//     deep[u] = cnt;
//     num[u] = 1;
//     son[u] = 0;
//     int mx = 0, tmp;
//     for (int i = head[u]; ~i; i = edge[i].nxt) {
//         int v = edge[i].v;
//         if (v == fa) continue;
//         tmp = dfs1(v, u, cnt + 1);
//         if (tmp > mx) mx = tmp, son[u] = v;
//         num[u] += tmp;
//     }
//     return num[u];
// }
// void dfs2(int u, int t) {
//     top[u] = t;
//     p[u] = totp++;
//     fp[p[u]] = u;
//     if (son[u])
//         dfs2(son[u], t);
//     else
//         return;
//     for (int i = head[u]; ~i; i = edge[i].nxt) {
//         int v = edge[i].v;
//         if (v == f[u]) continue;
//         if (v == son[u]) {
//             d[p[v]] = edge[i].c;
//             continue;
//         }
//         dfs2(v, v);
//         d[p[v]] = edge[i].c;
//     }
// }
// void PushUP(int rt) {
//     Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
//     Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
// }
// void build(int l, int r, int rt) {
//     if (l == r) {
//         Min[rt] = Max[rt] = d[l];
//         return;
//     }
//     int m = (l + r) >> 1;
//     build(lson);
//     build(rson);
//     PushUP(rt);
// }
// int query1(int L, int R, int l, int r, int rt) {
//     if (L <= l && R >= r) return Min[rt];
//     int m = (l + r) >> 1;
//     int ret = INF;
//     if (L <= m) ret = min(ret, query1(L, R, lson));
//     if (R > m) ret = min(ret, query1(L, R, rson));
//     return ret;
// }
// int query2(int L, int R, int l, int r, int rt) {
//     if (L <= l && R >= r) return Max[rt];
//     int m = (l + r) >> 1;
//     int ret = -INF;
//     if (L <= m) ret = max(ret, query2(L, R, lson));
//     if (R > m) ret = max(ret, query2(L, R, rson));
//     return ret;
// }
// void solve(int u, int v, int n) {
//     int f1 = top[u], f2 = top[v], ans1 = INF, ans2 = -INF;
//     while (f1 != f2) {
//         if (deep[f1] < deep[f2]) {
//             swap(f1, f2);
//             swap(u, v);
//         }
//         ans1 = min(ans1, query1(p[f1], p[u], 1, n - 1, 1));
//         ans2 = max(ans2, query2(p[f1], p[u], 1, n - 1, 1));
//         u = f[f1];
//         f1 = top[u];
//     }

//     if (u != v) {
//         if (deep[u] > deep[v]) swap(u, v);
//         ans1 = min(ans1, query1(p[son[u]], p[v], 1, n - 1, 1));
//         ans2 = max(ans2, query2(p[son[u]], p[v], 1, n - 1, 1));
//     }
//     printf("%d %d\n", ans1, ans2);
// }
// void print(int l, int r, int rt) {
//     if (l == r) {
//         printf("%d%c", Min[rt], l == totp - 1 ? '\n' : ' ');
//         return;
//     }
//     int m = (l + r) >> 1;
//     print(lson);
//     print(rson);
// }
// int main() {
//     int T, n, m;
//     scanf("%d", &T);
//     for (int cas = 1; cas <= T; cas++) {
//         tot = 0;
//         totp = 0;
//         memset(head, -1, sizeof(head));
//         printf("Case %d:\n", cas);
//         scanf("%d", &n);
//         for (int i = 0; i < n - 1; i++) {
//             int u, v, c;
//             scanf("%d%d%d", &u, &v, &c);
//             add(u, v, c);
//             add(v, u, c);
//         }
//         dfs1(1, 0, 1);
//         dfs2(1, 1);
//         build(1, totp - 1, 1);
//         scanf("%d", &m);
//         while (m--) {
//             int u, v;
//             scanf("%d%d", &u, &v);
//             solve(u, v, totp);
//         }
//     }
//     return 0;
// }