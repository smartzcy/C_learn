#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4;
int n, m;
vector<int> vec[N];
int num[N];
bool flag = true;
bool f[N];
void bfs(int u, int fa) {
    f[u] = 1;
    for (auto v : vec[u]) {
        if (fa == v) continue;
        if (num[v] == num[u]) flag = false;
        if (f[v]) continue;
        bfs(v, u);
    }
}
int main() {
    int V, E, K;
    cin >> V >> E >> K;
    for (int i = 1, u, v; i <= V; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int N;
    cin >> N;
    while (N--) {
        flag = true;
        for (int i = 1; i <= V; i++) {
            cin >> num[i];
            f[i] = 0;
        }
        bfs(1, 0);
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}