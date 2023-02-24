#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int a[N], b1[N], b2[N];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int val) {
    int val1 = val;
    int val2 = val * x;
    while (x <= n) {
        a[x] += val;
        x += lowbit(x);
    }
}
int getSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += a[x];
        x -= lowbit(x);
    }
}
int main() {
    cin >> n >> m;
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            int l, r, K, D;
            cin >> l >> r >> K >> D;
            add(l, K);
            add(l + 1, D - K);
            add(r + 1, -D);
        } else {
            int p;
            cin >> p;
        }
    }
}