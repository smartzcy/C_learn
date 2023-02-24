#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
int a[N], b[N], c[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        int ans = k * a[i] - c[k];
        cout << ans << endl;
    }
}