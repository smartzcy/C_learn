#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int inf = 1e9;
long long d[N][N];
int n, m, x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = inf;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i][x] + d[x][i]);
    }
    cout << ans << endl;
}