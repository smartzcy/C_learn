#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            int cnt = i - 1;
            cnt += (n - i) / i;
            if (n % i) cnt++;
            if (cnt <= ans)
                ans = cnt;
            else
                break;
        }
        cout << ans << endl;
    }
}