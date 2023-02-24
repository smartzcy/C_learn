// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int N = 1e5;
// vector<pair<int, int>> vec[N];
// int par[N][31], val[N][30], dep[N];
// int Min[N][30], Max[N][30];
// int n, m, q;
// int ans1 = 2e9, ans2 = -2e9;
// void dfs(int u, int f) {
//     dep[u] = dep[f] + 1;
//     for (auto &[v, w] : vec[u]) {
//         if (v == f) continue;
//         par[v][0] = u;
//         Min[v][0] = w;
//         Max[v][0] = w;
//         dfs(v, u);
//     }
// }
// void query(int u, int v) {
//     if (dep[u] < dep[v]) swap(u, v);
//     int d = 0;
//     for (; 1 << d <= dep[u]; d++)
//         ;
//     d--;
//     for (int j = d; j >= 0; j--)
//         if (dep[j] - (1 << j) >= dep[v]) {
//             ans1 = min(Min[v][j], ans1);
//             ans2 = max(Max[v][j], ans2);
//             v = par[u][j];
//         }
//     if (u == v) return;
//     for (int j = d; j >= 0; j--)
//         if (par[u][j] != par[v][j]) {
//             ans1 = min({ans1, Min[u][j], Min[v][j]});
//             ans2 = max({ans2, Max[u][j], Max[v][j]});
//             u = par[u][j];
//             v = par[v][j];
//         }
//     ans1 = min({ans1, Min[u][0], Min[v][0]});
//     ans2 = max({ans2, Max[u][0], Max[u][0]});
//     return;
// }
// int main() {
//     int T;
//     cin >> T;
//     for (int k = 1; k <= T; k++) {
//         cout << "Case " << k << ":" << endl;
//         cin >> n;
//         for (int i = 1; i <= n; i++) {
//             vec[i].clear();
//             for (int j = 0; j <= 30; j++) {
//                 Min[i][j] = 1e9;
//                 Max[i][j] = 0;
//             }
//         }
//         for (int i = 1, u, v, w; i < n; i++) {
//             cin >> u >> v >> w;
//             vec[u].push_back({v, w});
//             vec[v].push_back({u, w});
//         }
//         dfs(1, 0);
//         for (int j = 1; j <= 30; j++) {
//             for (int u = 1; u <= n; u++) {
//                 par[u][j] = par[par[u][j - 1]][j - 1];
//                 Min[u][j] = min(Min[u][j - 1], Min[par[u][j - 1]][j - 1]);
//                 Max[u][j] = max(Max[u][j - 1], Max[par[u][j - 1]][j - 1]);
//             }
//         }
//         cin >> m;
//         while (m--) {
//             ans1 = 2e9;
//             ans2 = 0;
//             int x, y;
//             cin >> x >> y;
//             query(x, y);
//             cout << ans1 << " " << ans2 << endl;
//         }
//     }
// }

/*除去冗长的头文件*/
const double PI = 3.1415926535898;
const double eps = 1e-10;
const int MAXM = 1e5 + 5;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, cost, nxt;
} E[MAXN << 1];

int Head[MAXN], tot;
int deep[MAXN];
int p[MAXN][20];
int Mi[MAXN][20];
int Ma[MAXN][20];

void edge_init() {
    tot = 0;
    mem(Head, -1);
    mem(p, -1);
    mem(Ma, 0);
    mem(Mi, 0x3f);
}

void add_edge(int u, int v, int cost) {
    E[tot].u = u;
    E[tot].v = v;
    E[tot].cost = cost;
    E[tot].nxt = Head[u];
    Head[u] = tot++;
}

void dfs(int u, int pre, int d) {
    deep[u] = d;
    for (int i = Head[u]; ~i; i = E[i].nxt) {
        int v = E[i].v;
        if (v == pre) continue;
        dfs(v, u, d + 1);
        p[v][0] = u;
        Mi[v][0] = E[i].cost;
        Ma[v][0] = E[i].cost;
    }
}

void b_init(int max_n) {
    for (int j = 1; 1 << j <= max_n; j++) {
        for (int i = 1; i <= max_n; i++) {
            if (p[i][j - 1] != -1) {
                p[i][j] = p[p[i][j - 1]][j - 1];
                Mi[i][j] = min(Mi[i][j - 1], Mi[p[i][j - 1]][j - 1]);
                Ma[i][j] = max(Ma[i][j - 1], Ma[p[i][j - 1]][j - 1]);
            }
        }
    }
}

PII LCA(int a, int b) {
    int Max = 0, Min = INF;
    if (deep[a] < deep[b]) swap(a, b);
    int dcp = 0;
    for (; 1 << dcp <= deep[a]; dcp++)
        ;
    dcp--;

    for (int j = dcp; j >= 0; j--) {
        if (deep[a] - (1 << j) >= deep[b]) {
            Max = max(Max, Ma[a][j]);
            Min = min(Min, Mi[a][j]);
            a = p[a][j];
        }
    }

    if (a == b) return make_pair(Min, Max);

    for (int j = dcp; j >= 0; j--) {
        if (p[a][j] != -1 && p[a][j] != p[b][j]) {
            Max = max(Max, Ma[a][j]);
            Min = min(Min, Mi[a][j]);
            Max = max(Max, Ma[b][j]);
            Min = min(Min, Mi[b][j]);
            a = p[a][j];
            b = p[b][j];
        }
    }
    Max = max(Max, Ma[a][0]);
    Min = min(Min, Mi[a][0]);
    Max = max(Max, Ma[b][0]);
    Min = min(Min, Mi[b][0]);
    return make_pair(Min, Max);
}

int T, n;

int main() {
#ifndef ONLINE_JUDGE
    FIN;
    // FOUT;
#endif
    IO_Init();
    int cas = 1;
    scanf("%d", &T);
    while (T--) {
        int u, v, cost;
        edge_init();
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d", &u, &v, &cost);
            add_edge(u, v, cost);
            add_edge(v, u, cost);
        }
        dfs(1, 0, 0);
        b_init(n);
        int q, a, b;
        printf("Case %d:\n", cas++);
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &a, &b);
            PII p = LCA(a, b);
            printf("%d %d\n", p.first, p.second);
        }
    }

    return 0;
}