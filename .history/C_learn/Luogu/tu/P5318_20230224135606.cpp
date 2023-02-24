#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
    queue<int> q;
    q.push(u);
    flag[u] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto &v : vec[x]) {
            if (flag[v]) continue;
            q.push(v);
            flag[v] = true;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
    }
    dfs(1);
    INIT();
    cout << endl;
    bfs(1);
}