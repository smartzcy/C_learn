#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1e5;
int n, m, a[N], sumL[N], sumR[N];
void solve() {
    stack<int> L, R;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (!L.empty() && a[L.top()] > a[i]) {
            L.pop();
        }
        sumL[i] = sumL[i] + (i - L.top()) * a[i];
        L.push(i);
    }
    cout << "1" << endl;
    int t, s = 0;
    for (int i = n; i >= 1; i--) {
        while (!R.empty() && a[i] < a[R.top()]) {
            R.pop();
        }
        sumR[i] = sumR[i] + (R.top() - i) * a[i];
        R.push(i);
        if (sumL[i] + sumR[i] - a[i] > s) {
            s = sumL[i] + sumR[i] - a[i];
            t = i;
        }
    }
    for (int i = t - 1; i > 0; i--) {
        if (a[i] > a[i + 1]) a[i] = a[i + 1];
    }
    for (int i = t + 1; i <= n; i++) {
        if (a[i] > a[i - 1]) a[i] = a[i - 1];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}