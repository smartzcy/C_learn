#include <iostream>
using namespace std;
int lowbit(int x) {
    return x & -x;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, ans = 0;
        cin >> n;
        string str;
        cin >> str;
        str = " " + str;
        for (int i = 1; i <= n; i++) {
            if (str[i] == '1') {
                ans++;
                int x = i;
                while (x <= n) {
                    if (str[x] == '1')
                        str[x] = '0';
                    else
                        str[x] = '1';
                    x += lowbit(x);
                }
            }
        }
        cout << ans << endl;
    }
}