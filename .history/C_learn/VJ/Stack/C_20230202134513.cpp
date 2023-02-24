#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
const int N = 1e5;
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    deque<int> q;
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && i - q.front() >= m) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= m) {
            cout << a[q.front()] << " \n"[i == n];
        }
    }
}
int main() {
    solve();
}