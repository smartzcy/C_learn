#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1), ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    deque<int> q, q1;
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && i - q.front() >= m) {
            q.pop_front();
        }
        while (!q1.empty() && i - q1.front() >= m) {
            q1.pop_front();
        }
        while (!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        while (!q1.empty() && a[q1.back()] <= a[i]) {
            q1.pop_back();
        }
        q.push_back(i);
        q1.push_back(i);
        if (i >= m) {
            cout << a[q.front()] << " \n"[i == n];
            ans[i] = a[q1.front()];
        }
    }
    for (int i = m; i <= n; i++) cout << ans[i] << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}