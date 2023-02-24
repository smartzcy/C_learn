#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
vector<int> g[N];
int num[N], val[N];
int n, m, r;
int L[N], R[N], tot;
void dfs(int x, int fa) {
    L[x] = ++tot;
    for (auto &u : g[x]) {
        if (u == fa) continue;
        dfs(u, x);
    }
    R[x] = tot;
}
int query(int u, int fa) {
    int ans = num[u];
    for (auto &v : g[u]) {
        if (v == fa) continue;
        ans += query(v, u);
    }
    return ans;
}
int main() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while (m--) {
        int k, a, x;
        cin >> k >> a;
        if (k == 1) {
            cin >> x;
            num[a] += x;
        } else {
            cout << query(a, 0) << endl;
        }
    }
}