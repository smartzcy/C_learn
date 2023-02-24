#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6;
int n, m;
int num[N], k[N], stk[N], tt = 0;
int main() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        while (tt && num[stk[tt]] < num[i]) {
            cnt++;
            cnt = max(cnt, k[stk[tt]]);
            k[i] = cnt;
            tt--;
        }
        ans = max(ans, cnt);
        stk[++tt] = i;
    }
    cout << ans << endl;
}