#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9;
int n, q;
int x1, y1, x2, y2;
string str[2];
long long d[2][N];
bool dis[2][N];
int u[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs() {
    queue<pair<int, int>> que;
    que.push({x1, y1});
    d[x1][y1] = 0;
    while (!que.empty()) {
        pair<int, int> p = que.front();
        dis[p.first][p.second] = 1;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int xx = p.first + u[i][0];
            int yy = p.second + u[i][1];
            if (xx < 0 || yy < 0 || xx > 1 || yy >= n) continue;
            if (dis[xx][yy] || str[xx][yy] == 'X') continue;
            // cout << xx << " " << yy << endl;
            d[xx][yy] = min(d[xx][yy], d[p.first][p.second] + 1);
            que.push({xx, yy});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    cin >> str[0] >> str[1];
    while (q--) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = 0;
                d[i][j] = inf;
            }
        }
        int u, v;
        cin >> u >> v;
        x1 = (u - 1) / n;
        x2 = (v - 1) / n;
        y1 = u - x1 * n - 1;
        y2 = v - x2 * n - 1;
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        bfs();
        if (d[x2][y2] == inf)
            cout << "-1" << endl;
        else
            cout << d[x2][y2] << endl;
    }
}