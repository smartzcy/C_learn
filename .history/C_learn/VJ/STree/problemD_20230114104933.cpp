#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N];
string s;
struct Info {
    int ans, pre, suf;
};
Info operator+(const Info &a, const Info &b) {
    Info c;
    int cnt = min(a.pre, b.suf);
    c.ans = a.ans + b.ans + 2 * cnt;
    c.pre = a.pre + b.pre - cnt;
    c.suf = a.suf + b.suf - cnt;
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
        if (s[l] == '(') {
            seg[id].val.pre = 1;
        } else {
            seg[id].val.suf = 1;
        }
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
    cin >> s;
    s = "?" + s;
    build(1, 1, s.size());
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, l, r).ans << endl;
    }
}