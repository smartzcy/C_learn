#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int num[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    while (m--) {
        int x;
        cin >> x;
        int ans = lower_bound(num + 1, num + 1 + n, x) - num;
        if (x != num[ans])
            cout << -1 << " ";
        else
            cout << ans << " ";
    }
}