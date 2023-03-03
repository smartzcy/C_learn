// #include <iostream>
// #include <algorithm>
// #include <map>
// using namespace std;
// const int N = 1e4 + 10;
// int n, m;
// int a[N], nam[N];
// double num[N][N];
// double find(int x) {
//     double maxn = -1.0;
//     for (int i = 0; i < n; i++) {
//         if (nam[i] == nam[x]) continue;
//         maxn = max(maxn, num[x][i]);
//     }
//     return maxn;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     for (int i = 0, k; i < m; i++) {
//         cin >> k;
//         double t = 1.0 / k;
//         for (int j = 0; j < k; j++) {
//             cin >> a[j];
//             if (a[j] < 0) {
//                 a[j] = -a[j];
//                 nam[a[j]] = 1;
//             }
//         }
//         for (int j = 0; j < k - 1; j++) {
//             for (int o = j + 1; o < k; o++) {
//                 int x = a[j], y = a[o];
//                 if (nam[x] == nam[y]) continue;
//                 num[x][y] += t;
//                 num[y][x] += t;
//             }
//         }
//     }
//     int a, b;
//     cin >> a >> b;
//     a = abs(a);
//     b = abs(b);
//     double ma = find(a);
//     double mb = find(b);
//     if (ma == mb && ma == num[a][b]) {
//         if (nam[a])
//             cout << -a;
//         else
//             cout << a;
//         cout << " ";
//         if (nam[b])
//             cout << -b;
//         else
//             cout << b;
//     } else {
//         for (int i = 0; i < n; i++) {
//             if (nam[i] == nam[a]) continue;
//             if (num[a][i] == ma) {
//                 if (nam[a])
//                     cout << -a;
//                 else
//                     cout << a;
//                 cout << " ";
//                 if (nam[i])
//                     cout << -i;
//                 else
//                     cout << i;
//                 cout << endl;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             if (nam[i] == nam[b]) continue;
//             if (num[b][i] == mb) {
//                 if (nam[b])
//                     cout << -b;
//                 else
//                     cout << b;
//                 cout << " ";
//                 if (nam[i])
//                     cout << -i;
//                 else
//                     cout << i;
//                 cout << endl;
//             }
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
double g[N][N];
bool xb[N];
int n, m;
int a[505];
int read() {
    string s;
    cin >> s;
    bool man = false;
    if (s[0] != '-')
        man = true;
    else
        s = s.substr(1, s.size() - 1);
    int x = 0;
    for (int i = 0; i < s.size(); ++i) {
        x *= 10;
        x += s[i] - '0';
    }
    xb[x] = man;
    return x;
}
double find(int x) {
    double res = -1;
    for (int i = 0; i < n; ++i) {
        if (xb[x] != xb[i]) {
            res = max(res, g[x][i]);
        }
    }
    return res;
}
void out(int x) {
    if (xb[x] == false) cout << "-";
    cout << x;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        double t = 1.0 / k;
        for (int j = 0; j < k; ++j) a[j] = read();
        for (int j = 0; j < k - 1; ++j) {
            for (int o = j + 1; o < k; ++o) {
                int x = a[j], y = a[o];
                if (xb[x] == xb[y]) continue;
                g[x][y] += t;
                g[y][x] += t;
            }
        }
    }
    int x, y;
    x = read();
    y = read();
    double mx = 0, my = 0;
    mx = find(x);
    my = find(y);
    if (g[x][y] == mx && mx == my) {
        out(x);
        cout << " ";
        out(y);
    } else {
        for (int i = 0; i < n; ++i) {
            if (xb[i] != xb[x] && g[x][i] == mx) {
                out(x);
                cout << " ";
                out(i);
                cout << endl;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (xb[i] != xb[y] && g[y][i] == my) {
                out(y);
                cout << " ";
                out(i);
                cout << endl;
            }
        }
    }
}
