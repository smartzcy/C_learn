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
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int a[501][501];
    int v, e, k;
    cin >> v >> e >> k;
}