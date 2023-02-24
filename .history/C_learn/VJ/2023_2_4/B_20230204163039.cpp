#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2e6;
int n, m, a[N], f[N];
vector<int> vec[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = i;
        vec[i].push_back(i);
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        int fu = find(u);
        int fv = find(v);
        if (fu != fv) {
            f[fv] = fu;
            vec[fu].insert(vec[fu].end(), vec[fv].begin(), vec[fv].end());
            vec[fv].clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) sort(vec[i].begin(), vec[i].end());
    }
    for (int i = 1; i <= n; i++) {
        int fi = find(a[i]);
        cout << vec[fi][vec[fi].size() - 1] << " ";
        vec[fi].pop_back();
    }
}