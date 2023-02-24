// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// const int N = 1e5;
// vector<int> vec[N];
// set<int> an;
// int n, sz[N], maxx[N], ans = 2e9;
// void dfs(int u, int fa) {
//     sz[u] = 1;
//     maxx[u] = 0;
//     for (int i = 0; i < vec[u].size(); i++) {
//         int v = vec[u][i];
//         if (fa != v) {
//             dfs(v, u);
//             sz[u] += sz[v];
//             maxx[u] = max(maxx[u], sz[v]);
//         }
//     }
//     maxx[u] = max(maxx[u], n - sz[u]);
//     if (maxx[u] < ans) {
//         ans = maxx[u];
//         an.clear();
//         an.insert(u);
//     } else if (maxx[u] == ans) {
//         an.insert(u);
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1, u, v; i < n; i++) {
//         cin >> u >> v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);
//     }
//     dfs(1, 1);
//     for (set<int>::iterator it = an.begin(); it != an.end(); it++) {
//         cout << *it << " ";
//     }
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5;
const int INF = 2e9;
vector<int> vec;
int n, tot, ans = 2e9;
int Head[N], Next[N], fa[N], U[N], V[N], Size[N], mx[N];
void add(int u, int v) {
    tot++;
    U[tot] = u;
    V[tot] = v;
    Next[tot] = Head[u];
    Head[u] = tot;
}
void dfs(int x) {
    Size[x] = 1;
    for (int i = Head[x]; i; i = Next[i]) {
        int y = V[i];
        if (fa[x] != y) {
            fa[y] = x;
            dfs(y);
            Size[x] += Size[y];
            mx[x] = max(mx[x], Size[y]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        int tmp = max(mx[i], n - Size[i]);
        if (tmp < ans) {
            ans = tmp;
            vec.clear();
            vec.push_back(i);
        } else if (tmp == ans)
            vec.push_back(i);
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}