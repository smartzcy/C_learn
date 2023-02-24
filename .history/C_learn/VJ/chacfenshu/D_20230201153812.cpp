#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
vector<int> g[N];
int num[N], val[N];
int n, m, r;
int L[N], R[N], tot;
struct node {
    int l, r, val;
    int lazy;
} tr[N << 2];
void build(int u, int l, int r) {
    tr[u] = {l, r, -1, 0};
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}
void settag(int id, long long tag) {
    tr[id].val += (tr[id].r - tr[id].l + 1) * tag;
    tr[id].lazy += tag;
}
void down(int id) {
    if (tr[id].lazy == 0) return;
    settag(id << 1, tr[id].lazy);
    settag(id << 1 | 1, tr[id].lazy);
    tr[id].lazy = 0;
}
void dfs(int x, int fa) {
    L[x] = ++tot;
    for (auto &u : g[x]) {
        if (u == fa) continue;
        dfs(u, x);
    }
    R[x] = tot;
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
        } else {
        }
    }
}