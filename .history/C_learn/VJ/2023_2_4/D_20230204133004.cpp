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
map<array<int, 3>, int> map1;
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
            num++;
            ans += w;
            f[fu] = fv;
        }
    }
}
int main() {
    cin >> n >> m >> q;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        edge[i] = {w, u, v};
        map1[{w, u, v}] = 1;
    }
}