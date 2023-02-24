#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100;
int n, m;
vector<int> vec[N];
int a[N], b[N], dp[N][N], ans[N], vis[N];
map<int, int> mp;
void dfs(int u, int w) {
    vis[u] = 1;
    ans[u] = max(w, ans[u]);
    for (auto v : vec[u]) {
        if (!vis[v]) {
            if (mp[a[v]]) {
                vis[v] = 1;
                dfs(v, w);
                vis[v] = 0;
            } else {
                vis[v] = 1;
                mp[a[v]]++;
                dfs(v, w + b[a[v]]);
                mp[a[v]] = 0;
                vis[v] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        dp[u][v] = 1;
    }
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            for (int k = 1; k <= v; k++)
                if (dp[u][v] && dp[u][k] && dp[k][v])
                    dp[u][v] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dp[i][j])
                vec[i].push_back(j);
    ans[1] = b[a[1]];
    mp[a[1]] = 1;
    dfs(1, b[a[1]]);
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}