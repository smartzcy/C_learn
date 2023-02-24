#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> vec[N];
int n, m;
int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ":" << endl;
        cin >> n;
        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            vec[u].push_back({v, w});
            vec[v].push_back({u, w});
        }
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
        }
    }
}