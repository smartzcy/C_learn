#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m;
long long a[N], d[N], b1[N], b2[N];
long long lowbit(long long x) {
    return x & -x;
}
void add(long long x, long long val) {
    long long val1 = val;
    long long val2 = val * x;
    while (x <= n) {
        b1[x] += val1;
        b2[x] += val2;
        x += lowbit(x);
    }
}
long long getSum(long long x) {
    long long sum1 = 0;
    long long sum2 = 0;
    long long xx = x;
    while (x > 0) {
        sum1 += b1[x];
        sum2 += b2[x];
        x -= lowbit(x);
    }
    return sum1 * (xx + 1) - sum2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        add(i, d[i] - d[i - 1]);
    }
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            int l, r, K, D;
            cin >> l >> r >> K >> D;
            add(l, K);
            add(l + 1, D - K);
            add(r + 1, -(r - l + 1) * D - K);
            add(r + 2, K + (r - 1) * D);
        } else {
            int p;
            cin >> p;
            cout << getSum(p) << endl;
        }
    }
}