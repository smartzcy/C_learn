#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1e5;
vector<int> vec[N];
set<int> an;
int n, sz[N], maxx[N], ans = 2e9;
void dfs(int u, int fa) {
    sz[u] = 1;
    maxx[u] = 0;
    for (auto &v : vec[u]) {
        if (fa != v) {
            dfs(v, u);
            sz[u] += sz[v];
            maxx[u] = max(maxx[u], sz[v]);
        }
    }
    maxx[u] = max(maxx[u], n - sz[u]);
    if (maxx[u] < ans) {
        ans = maxx[u];
        an.clear();
        an.insert(u);
    } else if (maxx[u] == ans) {
        an.insert(u);
    }
}
int main() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
    }
    dfs(1, 1);
    for (auto i : an) {
        cout << i << endl;
    }
}