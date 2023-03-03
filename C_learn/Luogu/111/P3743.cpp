#include <iostream>
#include <algorithm>
using namespace std;
const double P = 1e-6;
const int N = 1e5 + 10;
int n, p;
pair<double, double> vec[N];
bool check(double x) {
    double q = x * p;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        if (vec[i].first * x <= vec[i].second) continue;
        sum += (vec[i].first * x - vec[i].second);
    }
    return sum <= q;
}
int main() {
    cin >> n >> p;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        double a, b;
        cin >> a >> b;
        vec[i] = {a, b};
        sum += a;
    }
    if (sum <= p) {
        cout << -1 << endl;
        return 0;
    }
    double l = 0.0, r = 1e10;
    while ((r - l) > P) {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}