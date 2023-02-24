#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, q, a[N];
struct node {
    int l, r;
    int sum, ans;
} seg[N << 2];
node up(node &L, node &R) {
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].val.ans = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void change(int id, int pos, int val) {
    if (seg[id].l == seg[id].r) {
        seg[id].val.ans = val;
        return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (pos <= mid)
        change(id << 1, pos, val);
    else
        change(id << 1 | 1, pos, val);
    up(id);
}
Info query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql <= l && r <= qr) return seg[id].val;
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(id << 1, ql, qr);
    else if (ql > mid)
        return query(id << 1 | 1, ql, qr);
    else
        return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 0) {
            change(1, x, y);
        } else if (k == 1) {
            cout << query(1, x, y).ans << endl;
        }
    }
}