#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
vector<int> vec[N];
int dp[N][20], deep[N], nm;
int n, m;
void dfs(int u, int fa, int dep) {
    deep[u] = dep;
    dp[u][0] = fa;
    for (int i = 1; i <= nm; i++) {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto v : vec[u]) {
        if (v != fa) {
            dfs(v, u, dep + 1);
        }
    }
}
int main() {
    cin >> n >> m;
    nm = log2(n) + 1;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, 0, 0);
}