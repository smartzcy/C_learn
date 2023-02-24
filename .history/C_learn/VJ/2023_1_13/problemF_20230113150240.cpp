#include <iostream>
using namespace std;
int lowbit(int x) {
    return x & -x;
}
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        long long ans = 0, a[100010];
        cin >> n;
        for (int i = 1; i <= n; i++) a[i] = 0;
        string str;
        cin >> str;
        str = " " + str;
        for (int i = 1; i <= n; i++) {
            if (str[i] == '1') {
                int x = i;
                while (x + lowbit(x) <= n) {
                    a[x + lowbit(x)]++;
                    x += lowbit(x);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (str[i] == '1' && a[i] == 0)
                ans++;
            else if (str[i] == '0' && a[i] == 1)
                ans++;
        }
        cout << ans << endl;
    }
}