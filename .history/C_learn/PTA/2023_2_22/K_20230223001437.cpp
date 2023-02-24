// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int N = 1e4;
// int n, m;
// vector<int> vec[N];
// int num[N];
// bool flag = true;
// bool f[N];
// void bfs(int u, int fa) {
//     f[u] = 1;
//     for (auto v : vec[u]) {
//         if (fa == v) continue;
//         if (num[v] == num[u]) flag = false;
//         if (f[v]) continue;
//         bfs(v, u);
//     }
// }
// int main() {
//     int V, E, K;
//     cin >> V >> E >> K;
//     for (int i = 1, u, v; i <= E; i++) {
//         cin >> u >> v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);
//     }
//     int N;
//     cin >> N;
//     while (N--) {
//         flag = true;
//         map<int, int> map1;
//         for (int i = 1; i <= V; i++) {
//             cin >> num[i];
//             map1[num[i]] = 1;
//             f[i] = 0;
//         }
//         if (map1.size() != K) flag = 0;
//         bfs(1, 0);
//         if (flag)
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//     }
// }

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int a[501][501];
int v, e, k;
int main() {
    cin >> v >> e >> k;
    for (int i = 1, x, y; i <= e; i++) {
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int n;
    cin >> n;
    while (n--) {
        int b[501];
        set<int> s1;
        for (int i = 1; i <= v; i++) {
            cin >> b[i];
            s1.insert(b[i]);
        }
        if (s1.size() != k) {
            cout << "No" << endl;
            continue;
        }
        int flag = 1;
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if ((a[i][j] == 1 || a[j][i] == 1) && b[i] == b[j])
                    flag = 0;
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}