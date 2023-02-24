// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;
// const int N = 1000;
// const int inf = 1e8;
// int n, m, q, ans;
// int d[N][N];
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m >> q;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             d[i][j] = inf;
//     for (int i = 1, u, v, w; i <= m; i++) {
//         cin >> u >> v >> w;
//         d[u][v] = w;
//         d[v][u] = w;
//     }
//     for (int k = 1; k <= n; k++) {
//         for (int u = 1; u <= n; u++) {
//             for (int v = 1; v <= n; v++) {
//                 d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
//             }
//         }
//     }
//     for (int i = 1, u, v, w; i <= q; i++) {
//         cin >> u >> v >> w;
//         cout << d[u][v] << endl;
//         if (d[u][v] < w)
//             cout << "No" << endl;
//         else
//             cout << "Yes" << endl;
//     }
// }

// #include <iostream>
// #include <array>
// #include <algorithm>
// #include <map>
// using namespace std;
// const int N = 1e6;
// int n, m, q, f[N];
// void INIT() {
//     for (int i = 1; i <= n; i++) f[i] = i;
// }
// int find(int x) {
//     return x == f[x] ? x : f[x] = find(f[x]);
// }
// array<int, 3> edge[N];
// map<array<int, 3>, int> map1;
// int ans, num, a, b, c, flag;
// void kru() {
//     sort(edge + 1, edge + 1 + m);
//     INIT();
//     ans = 0;
//     num = 0;
//     for (int i = 1; i <= m; i++) {
//         auto [w, u, v] = edge[i];
//         if (map1[{w, u, v}] == 0) continue;
//         int fu = find(u);
//         int fv = find(v);
//         if (fu != fv) {
//             if (w == c && u == a && v == b) flag = 1;
//             num++;
//             ans += w;
//             f[fu] = fv;
//         }
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m >> q;
//     for (int i = 1, u, v, w; i <= m; i++) {
//         cin >> u >> v >> w;
//         edge[i] = {w, u, v};
//         map1[{w, u, v}] = 1;
//     }
//     for (int i = 1; i <= q; i++) {
//         m++;
//         flag = 0;
//         cin >> a >> b >> c;
//         edge[m] = {c, a, b};
//         map1[{c, a, b}] = 1;
//         kru();
//         if (flag == 1)
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//         map1[{c, a, b}] = 0;
//     }
// }

#include <iostream>
#include <array>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e6;
int n, m, q, f[N];
void INIT() {
    for (int i = 1; i <= n; i++) f[i] = i;
}
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
array<int, 3> edge[N];
map<pair<int, int>, int> map1;
int ans, num;
void kru() {
    sort(edge + 1, edge + 1 + m);
    INIT();
    ans = 0;
    num = 0;
    for (int i = 1; i <= m; i++) {
        auto [w, u, v] = edge[i];
        int fu = find(u);
        int fv = find(v);
        if (fu != fv) {
            map1[{u, v}] = w;
            num++;
            ans += w;
            f[fu] = fv;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        edge[i] = {w, u, v};
    }
    kru();
    for (int i = 1, u, v, w; i <= q; i++) {
        cin >> u >> v >> w;
    }
}