#include <iostream>
#include <algorithm>
using namespace std;
const int N = 6e4 + 10;
double maxn, minm;
double a[N];
double t[N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        double v;
        cin >> v;
        t[i] = a[i] / v;
    }
    sort(t + 1, t + 1 + n);
    cout << (t[n] - t[1]) / 2 << endl;
}