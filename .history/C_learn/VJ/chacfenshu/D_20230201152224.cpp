#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
vector<int> vec[N];
int num[N];
int n, m, r;
int L[N], R[N], tot;
// L[i] 即为 i 点为根的子树的最小点的编号
// R[i] 即为 i 点为根的子树的最大点的编号
void dfs(int x, int fa) {
    L[x] = ++tot;
    for (auto u : g[x]) {
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
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    while (m--) {
        int k, a, x;
        cin >> k >> a;
        if (k == 1) {
            cin >> x;

        } else {
        }
    }
}