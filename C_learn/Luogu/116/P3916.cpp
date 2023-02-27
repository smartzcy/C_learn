#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int fa[N];
void INIT() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> n >> m;
    INIT();
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        int fu = find(u);
        int fv = find(v);
        if (fu < fv) fa[fu] = fv;
    }
    for (int i = 1; i <= n; i++) cout << find(i) << " ";
}