#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
const int N = 1e5;
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1), ans1(n + 1), ans2(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    deque<int> q;
    deque<int> q1;
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
            ans1[i] = a[q.front()];
            ans2[i] = a[q1.front()];
        }
    }
    for (int i = 3; i <= n; i++) cout << ans1[i] << " ";
    cout << endl;
    for (int i = 3; i <= n; i++) cout << ans2[i] << " ";
}
int main() {
    solve();
}