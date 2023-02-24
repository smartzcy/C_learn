#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n = 0, m, q, a[N];
struct node {
    int l, r;
    int sum;
} seg[N << 2];
void up(int id) {
    seg[id].sum = max(seg[id << 1].sum, seg[id << 1 | 1].sum);
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
void change(int id, int pos, int val) {
    if (seg[id].l == seg[id].r) {
        seg[id].sum = max(seg[id].sum, val);
        return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (pos <= mid)
        change(id << 1, pos, val);
    else
        change(id << 1 | 1, pos, val);
    up(id);
}
int query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (qr >= r && ql <= l) return seg[id].sum;
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(id << 1, ql, qr);
    else if (ql > mid)
        return query(id << 1 | 1, ql, qr);
    else
        return max(query(id << 1, ql, qr), query(id << 1 | 1, ql, qr));
}
int main() {
    cin >> m >> q;
    int num = 0;
    while (m--) {
        string str;
        int t;
        cin >> str >> t;
        if (str == "A") {
            n++;
            a[n] = (t + num) % q;
            build(1, 1, n);
        } else if (str == "Q") {
            num = query(1, n - t + 1, n);
            cout << num << endl;
        }
    }
}