#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int N = 1e5;
int n, m, t, tot, ans;
vector<pair<int, int>> vec[N];
int a[N];
int dp[N];
void dfs(int u, int ti) {
    if (ti > t) return;
    if (a[u] != 0) {
        int tim = ti + min(a[u], (t - ti) / 5) * 5;
        if (tim <= t) {
            dp[tim] = max(dp[tim], dp[ti] + min(a[u], (t - ti) / 5));
        }
    }
    for (auto [v, w] : vec[u]) {
        dfs(v, ti + w * 2);
    }
}
int main() {
    cin >> t;
    stack<pair<int, int>> s;
    s.push({0, 1});
    while (!s.empty()) {
        cin >> n >> m;
        if (m == 0) {
            pair<int, int> p = s.top();
            s.pop();
            if (p.second != 1) s.push({p.first, 1});
            vec[p.first].push_back({++tot, n});
            s.push({tot, 2});
        } else {
            pair<int, int> p = s.top();
            s.pop();
            if (p.second != 1) s.push({p.first, 1});
            vec[p.first].push_back({++tot, n});
            a[tot] = m;
        }
    }
    dfs(0, 0);
    int ans = 0;
    for (int i = 1; i <= t; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}