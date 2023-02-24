#include <iostream>
using namespace std;
const int N = 1e6;
int n, m, f[N], d[N];
void INIT() {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        d[i] = 1;
    }
}
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
    cin >> n >> m;
    INIT();
    while (m--) {
        int k;
        cin >> k;
        if (k == 0) {
            int x, y;
            cin >> x >> y;
            int xx = find(x);
            int yy = find(y);
            if (xx != yy) {
                f[yy] == xx;
                d[xx] += d[yy];
                d[yy] = 0;
            }
        } else {
            int x;
            cin >> x;
        }
    }
}