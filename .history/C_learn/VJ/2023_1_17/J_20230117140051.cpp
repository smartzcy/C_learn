#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int N = 1e3 + 10;
int a[N], b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    priority_queue<int> que;
    for (int i = 1; i <= n; i++) que.push(fabs(a[i] - b[i]));
    for (int i = 1; i <= k1 + k2; i++) {
        int x = que.top();
        que.pop();
        x--;
        que.push(fabs(x));
    }
    long long sum = 0;
    while (!que.empty()) {
        long long x = que.top();
        que.pop();
        sum += x * x;
    }
    cout << sum;
}