#include <iostream>
#include <array>
using namespace std;
const int N = 1e3 + 10;
int d[N][N];
int n, m, x;
int main() {
    cin >> n >> m >> x;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
            }
        }
    }
}