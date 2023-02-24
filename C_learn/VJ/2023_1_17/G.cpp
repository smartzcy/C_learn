#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int N = 1e5;
int a[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int p = a[0], ans = 0;
    for (int i = 1; i < n; i++) p = __gcd(p, a[i]);
    for (int i = 0; i < n; i++) {
        int x = a[i] / p;
        while (x % 2 == 0) {
            x /= 2;
            ans++;
        }
        while (x % 3 == 0) {
            x /= 3;
            ans++;
        }
        if (x != 1) {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}