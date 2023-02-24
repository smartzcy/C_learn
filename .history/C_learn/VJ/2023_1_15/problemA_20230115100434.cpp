#include <iostream>
using namespace std;
long long Exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = Exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int main() {
    long long x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    long long a = n - m, b = l, d = x - y;
    long long r = __gcd(a, b);
    if (d % r != 0) {
        cout << "Impossible" << endl;
    } else {
        long long k1, k2;
        a /= r;
        b /= r;
        d /= r;
        Exgcd(a, b, k1, k2);
    }
}