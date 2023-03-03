#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
const double P = 1e-4;
int a, b, c;
bool check(double x) {
    double sum = a;
    for (int i = 1; i <= c; i++) {
        sum = sum * (1 + x) - b;
    }
    if (sum > 0)
        return true;
    else
        return false;
}
int main() {
    cin >> a >> b >> c;
    double l = 0.0, r = 5;
    while ((r - l) > P) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else
            l = mid;
    }
    printf("%.1f", l * 100);
}