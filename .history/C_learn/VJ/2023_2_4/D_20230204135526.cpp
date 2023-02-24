#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1000;
const int inf = 1e8;
int n, m, q, ans;
int d[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = inf;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }
    for (int i = 1, u, v, w; i <= q; i++) {
        cin >> u >> v >> w;
        cout << d[u][v] << endl;
        if (d[u][v] < w)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}