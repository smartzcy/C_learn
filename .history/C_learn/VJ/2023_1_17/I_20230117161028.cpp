#include <iostream>
#include <vector>
using namespace std;
const int N = 100;
int n, m;
int d[N], c[N], dis[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    while (m--) {
        int a, b, ans = 0;
        for (int i = a; i <= b; i++) {
            dis[i] = 0;
        }
        cin >> a >> b;
        for (int i = a; i <= b; i++) {
            if (dis[i] < d[i]) {
                ans += d[i] - dis[i];
                dis[i] = d[i];
            }
        }
        cout << ans << endl;
    }
}