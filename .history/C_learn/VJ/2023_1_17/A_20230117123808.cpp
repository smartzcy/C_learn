#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, q;
int x1, y1, x2, y2;
string str[2];
int d[2][N];
int dis[2][N];
int u[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs() {
    queue<pair<int, int>> que;
    que.push({x1, y1});
    while (!que.empty()) {
    }
}
int main() {
    cin >> n >> q;
    cin >> str[0] >> str[1];
    while (q--) {
        int u, v;
        cin >> u >> v;
        x1 = u / n;
        x2 = v / n;
        y1 = u - x1 * n;
        y2 = v - x2 * n;
    }
}