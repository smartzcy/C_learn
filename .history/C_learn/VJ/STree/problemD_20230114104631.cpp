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
}
struct node {
    int l, r;
    int sum;
} seg[N << 2];
void up(int id) {
    seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
int query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql <= l && r <= qr) return seg[id].sum;
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
    build(1, 1, s.length());
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, l, r) << endl;
    }
}