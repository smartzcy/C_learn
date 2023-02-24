#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], f[N];
vector<int> vec[N];
int find(int x) {
    return x == f[x] ? x : f[x] == find(x);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = i;
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        int fu = find(u);
        int fv = find(v);
        if (fu != fv) {
        }
    }
}