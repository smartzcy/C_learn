#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m, q, Np;
int flag[N], u[N], v[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
    }
    cin >> q;
    while (q--) {
        cin >> Np;
        for (int i = 1; i <= n; i++) {
            flag[i] = 0;
        }
        for (int i = 1, x; i <= Np; i++) {
            cin >> x;
            flag[x] = 1;
        }
        int f = 1;
        for (int i = 1; i <= m; i++) {
            if (flag[u[i]] == 0 && flag[v[i]] == 0) {
                f = 0;
                break;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}