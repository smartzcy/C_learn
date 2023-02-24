#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, q, a[N];
struct Info {
    int ans, pre, suf, sum;
};
Info operator+(const Info &a, const Info &b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.pre = max(a.pre, a.ans + b.pre);
    c.suf = max(b.suf, b.ans + a.suf);
    c.ans = max(a.suf + b.pre, max(a.ans, b.ans));
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
        seg[id].val.ans = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
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
    cin >> q;
    while (q--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 0) {
        } else if (k == 1) {
        }
    }
}