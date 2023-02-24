#include <iostream>
using namespace std;
const int N = 1e5;
int n, q, a[N];
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
    if (qr <= r && ql >= l) return seg[id].sum;
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(id << 1, ql, qr);
    else if (ql > mid)
        return query(id << 1 | 1, ql, qr);
    else
        return query(id << 1 | 1, ql, qr) + query(id << 1, ql, qr);
}
void change(int id, int pos, int val) {
    if (seg[id].l == seg[id].r) {
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ":" << endl;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1, 1, n);
        while (q--) {
            int k, i, j, v;
            cin >> k;
            if (k == 1) {
                cin >> i;
                i++;
                cout << a[i] << endl;
                if (a[i] != 0) {
                    change(1, i, -a[i]);
                    a[i] = 0;
                }
            } else if (k == 2) {
                cin >> i >> v;
                i++;
                change(1, i, v);
                a[i] += v;
            } else if (k == 3) {
                cin >> i >> j;
                cout << query(1, i + 1, j + 1) << endl;
            }
        }
    }
}