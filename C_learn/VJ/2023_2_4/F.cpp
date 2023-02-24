#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int w[N];
bool flag[N];
bool check(int x) {
    int ok2 = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        flag[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int cnt2 = 0;
        for (int j = 0; j < n; j++) {
            if (w[i * n + j] >= x) {
                cnt2++;
                if (!flag[j]) {
                    flag[j] = 1;
                    cnt++;
                }
            }
        }
        if (cnt2 > 1) ok2 = 1;
    }
    if (cnt == n && ok2)
        return 0;
    else
        return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> w[i * n + j];
        int l = 0, r = 1e9 + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else
                l = mid + 1;
        }
        cout << l - 1 << endl;
    }
}