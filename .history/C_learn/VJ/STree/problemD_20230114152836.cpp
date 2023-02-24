#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, q, a[N];
struct Info {
    int l, r, ans, sum;
};
Info operator+(const Info &a, const Info &b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.l = max(a.l, a.ans + b.l);
    c.r = max(b.r, b.ans + a.r);
    c.ans = max(max(a.ans, b.ans), a.r + b.l);
    return c;
}
struct node {
    int l, r;
    Info val;
} seg[N << 2];
void up(int id) {
    seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].val.sum = a[l];
        seg[id].val.ans = a[l];
        seg[id].val.l = a[l];
        seg[id].val.r = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void change(int id, int pos, int val) {
    if (seg[id].l == seg[id].r) {
        seg[id].val.sum = val;
        seg[id].val.ans = val;
        seg[id].val.l = val;
        seg[id].val.r = val;
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
        if (k == 0)
            change(1, x, y);
        else
            cout << query(1, x, y).ans << endl;
    }
}