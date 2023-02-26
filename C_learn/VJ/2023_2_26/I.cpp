#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int W, H;
        int x1, y1, x2, y2;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;
        int ans = 1e9;
        int le = x2 - x1, h1 = y2 - y1;
        if (w + le <= W) {
            ans = min(ans, max(0, w - x1));
            ans = min(ans, max(0, x2 - W + w));
        }
        if (h1 + h <= H) {
            ans = min(ans, max(0, h - y1));
            ans = min(ans, max(0, y2 - H + h));
        }
        if (ans == 1e9)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }
}