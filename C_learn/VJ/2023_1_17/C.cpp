#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 6e4 + 10;
const int inf = 1e9;
double maxn, minm;
double a[N];
double v[N];
int n;
bool check(double mid) {
    double maxx = -inf, minn = inf;
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx, a[i] - v[i] * mid);
        minn = min(minn, a[i] + v[i] * mid);
    }
    if (maxx <= minn)
        return 1;
    else
        return 0;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    double l = 0, r = 1e18;
    int cnt = 1000;
    while (cnt--) {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(10) << l << endl;
}