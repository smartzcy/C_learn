#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5;
int n, m;
struct node {
    int pos;
    int val;
    int id;
} seg[N << 2];
bool cmp1(const node &a, const node &b) {
    return a.val < b.val;
}
bool cmp2(const node &a, const node &b) {
    return a.pos < b.pos;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        map<int, int> map1;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> seg[i].pos >> seg[i].val;
            seg[i].id = i;
        }
        int ans = 0;
        sort(seg + 1, seg + 1 + m, cmp1);
        for (int i = 1; i <= 2 * n; i++) ans += seg[i].val;
        cout << ans << endl;
        sort(seg + 1, seg + 1 + 2 * n, cmp2);
        for (int i = 1; i <= n; i++) {
            cout << seg[i].id << " " << seg[2 * n + 1 - i].id << endl;
        }
    }
}