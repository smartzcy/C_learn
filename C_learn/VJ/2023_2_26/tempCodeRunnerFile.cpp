#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int l, r, a;
        cin >> l >> r >> a;
        int ans = r / a + r % a;
        int m = r / a * a - 1;
        if (m >= 1) ans = max(ans, m / a + m % a);
        cout << ans << endl;
    }
}