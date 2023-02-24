#include <iostream>
using namespace std;
int Exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, x, y);
    int t = x;
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
        a /= r;
        b /= r;
        d /= r;
    }
}