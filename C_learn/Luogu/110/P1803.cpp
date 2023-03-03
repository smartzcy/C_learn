#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int n, m;
struct node {
    int l, r;
} seg[N];
bool cmp(const node &a, const node &b) {
    if (a.r == b.r)
        return a.l > b.l;
    else
        return a.r < b.r;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seg[i].l >> seg[i].r;
    }
    sort(seg, seg + n, cmp);
    int last = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (last <= seg[i].l) {
            last = seg[i].r;
            cnt++;
        }
    }
    cout << cnt << endl;
}