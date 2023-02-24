#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int w[N];
int main() {
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
    }
}