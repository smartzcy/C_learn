#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
int n, q;
struct node {
    int l, r;
    int lmax, rmax;
} seg[N << 2];
void up(int id) {
    seg[id].lmax = seg[id << 1].lmax + (seg[id << 1].lmax == seg[id << 1].r - seg[id << 1].l + 1 ? seg[id << 1 | 1].lmax : 0);
    seg[id].rmax = seg[id << 1 | 1].rmax + (seg[id << 1 | 1].rmax == seg[id << 1 | 1].r - seg[id << 1 | 1].l + 1 ? seg[id << 1].rmax : 0);
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    seg[id].lmax = 1;
    seg[id].rmax = 1;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void change(int id, int pos, int val) {
    if (seg[id].l == seg[id].r) {
        seg[id].lmax = seg[id].rmax = val;
        return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (pos <= mid)
        change(id << 1, pos, val);
    else
        change(id << 1 | 1, pos, val);
    up(id);
}
int query(int id, int pos) {
    if (a[rt].l == a[rt].r) {
        return a[rt].lmax;
    }
    int mid = (a[rt].l + a[rt].r) / 2;
    Tunnel ls = a[rt << 1], rs = a[rt << 1 | 1];
    if (pos <= mid) {
        if ((ls.r - pos) < ls.rmax) {
            return ls.rmax + rs.lmax;
        } else
            return query(pos, rt << 1);
    } else {
        if ((pos - ls.r) <= rs.lmax) {
            return rs.lmax + ls.rmax;
        } else
            return query(pos, rt << 1 | 1);
    }
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
            cin >> x;
            cout << query(1, 1, n, x).ans << endl;
        }
    }
    return 0;
}