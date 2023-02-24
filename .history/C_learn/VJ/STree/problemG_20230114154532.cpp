#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
int n, q;
struct Info {
    long long l, r, ans;
};
Info operator+(const Info &a, const Info &b) {
    Info c;
    c.l = a.l;
    c.r = b.r;
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
        seg[id].val.ans = 1;
        seg[id].val.l = 1;
        seg[id].val.r = 1;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    build(1, 1, n);
    stack<int> sta;
    while (q--) {
        string k;
        int x;
        cin >> k;
        if (k == "D") {
            cin >> x;
            sta.push(x);
            change(1, x, 0);
        } else if (k == "R") {
            x = sta.top();
            sta.pop();
            change(1, x, 1);
        } else if (k == "Q") {
            cout << query(1, 1, n).ans << endl;
        }
    }
    return 0;
}