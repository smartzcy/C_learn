#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int n, m;
int num[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int b = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            if (num[i] < num[i - 1]) b = i;
        }
        if (b) {
            for (int i = 1; i <= b; i++)
                if (m < num[i]) {
                    swap(m, num[i]);
                    ans++;
                }
            for (int i = 1; i <= n; i++)
                if (num[i] < num[i - 1]) b = 0;
            if (b)
                cout << ans << endl;
            else
                cout << -1 << endl;
        } else
            cout << "0" << endl;
    }
}