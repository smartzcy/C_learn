#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
int n, m;
vector<int> vec[N];
bool flag[N];
void INIT() {
    for (int i = 1; i <= n; i++) flag[i] = false;
}
void dfs(int u) {
    cout << u << " ";
    flag[u] = true;
    for (auto &v : vec[u]) {
        if (flag[v]) continue;
        dfs(v);
    }
}
void bfs(int u) {
    cout << u << " ";
    flag[u] = true;
}
int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
    }
    dfs(1);
}