#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 100;
int n, m;
vector<int> vec[N];
int a[N], b[N], dp[N][N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        dp[u][v] = 1;
    }
}