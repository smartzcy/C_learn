#include <iostream>
using namespace std;
int lowbit(int x) {
    return x & -x;
}
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        int ans = 0, a[100000];
        cin >> n;
        for (int i = 1; i <= n; i++) a[i] = 0;
        string str;
        cin >> str;
        str = " " + str;
        for (int i = 1; i <= n; i++) {
        }
        cout << ans << endl;
    }
}