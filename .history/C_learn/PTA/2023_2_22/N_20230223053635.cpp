#include <iostream>
using namespace std;
const int N = 1e6 + 5;
long long n, q, a[N];
struct node {
    int l, r;
    long long sum, lazy;
} seg[N << 2];
void settag(int id, long long tag) {
    seg[id].sum += (seg[id].r - seg[id].l + 1) * tag;
    seg[id].lazy += tag;
}
void up(int id) {
    seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
}
void down(int id) {
    if (seg[id].lazy == 0) return;
    settag(id << 1, seg[id].lazy);
    settag(id << 1 | 1, seg[id].lazy);
    seg[id].lazy = 0;
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
    if (seg[id].r == seg[id].l) {
        seg[id].sum += val;
        return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (pos <= mid)
        change(id << 1, pos, val);
    else
        change(id << 1 | 1, pos, val);
    up(id);
}
void modify(int id, int ql, int qr, int val) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        settag(id, val);
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    modify(id << 1, ql, qr, val);
    modify(id << 1 | 1, ql, qr, val);
    up(id);
}
long long query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return seg[id].sum;
    down(id);
    return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
}
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    build(1, 1, n - 1);
    pair<int, int> p[N];
    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        p[i] = {r, l};
    }
    sort(p, p + q);
    long long sum = 0;
    for (int i = 0; i < q; i++) {
        int num = query(1, p[i].second + 1, p[i].first);
        sum += num;
    }
}
