// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5 + 5;
// long long n, q, a[N];
// struct node {
//     int l, r;
//     long long sum, lazy;
// } seg[N << 2];
// void settag(int id, long long tag) {
//     seg[id].sum -= tag;
//     seg[id].lazy += tag;
// }
// void up(int id) {
//     seg[id].sum = min(seg[id << 1].sum, seg[id << 1 | 1].sum);
// }
// void down(int id) {
//     if (seg[id].lazy == 0) return;
//     settag(id << 1, seg[id].lazy);
//     settag(id << 1 | 1, seg[id].lazy);
//     seg[id].lazy = 0;
// }
// void build(int id, int l, int r) {
//     seg[id].l = l;
//     seg[id].r = r;
//     if (l == r) {
//         seg[id].sum = a[l];
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
//     up(id);
// }
// void modify(int id, int ql, int qr, int val) {
//     int l = seg[id].l;
//     int r = seg[id].r;
//     if (ql > r || qr < l) return;
//     if (ql <= l && r <= qr) {
//         settag(id, val);
//         return;
//     }
//     int mid = (l + r) >> 1;
//     if (l <= mid) modify(id << 1, ql, qr, val);
//     if (r > mid) modify(id << 1 | 1, ql, qr, val);
//     up(id);
// }
// long long query(int id, int ql, int qr) {
//     int l = seg[id].l;
//     int r = seg[id].r;
//     if (ql > r || qr < l) return 0;
//     if (ql <= l && r <= qr) return seg[id].sum;
//     down(id);
//     int mid = (l + r) >> 1;
//     long long sum = 1e18;
//     if (l <= mid) sum = min(sum, query(id << 1, ql, mid));
//     if (r > mid) sum = min(sum, query(id << 1 | 1, mid + 1, qr));
//     return sum;
// }
// int main() {
//     int n, q;
//     cin >> n >> q;
//     for (int i = 1; i < n; i++) {
//         cin >> a[i];
//     }
//     build(1, 1, n - 1);
//     pair<int, int> p[N];
//     for (int i = 0, l, r; i < q; i++) {
//         cin >> l >> r;
//         if (l > r) swap(l, r);
//         p[i] = {r, l};
//     }
//     sort(p, p + q);
//     long long sum = 0;
//     for (int i = 0; i < q; i++) {
//         int num = query(1, p[i].second + 1, p[i].first);
//         sum += num;
//         modify(1, p[i].second + 1, p[i].first, num);
//     }
//     cout << sum << endl;
// }

#include <bits/stdc++.h>
using namespace std;
#define N 200005
int f[N];
long long Min[2 * N + 1], lazy[2 * N + 1];
void pushdown(int rt) {
    if (!lazy[rt]) return;
    lazy[rt * 2] += lazy[rt], lazy[rt * 2 + 1] += lazy[rt];
    Min[rt * 2] -= lazy[rt], Min[rt * 2 + 1] -= lazy[rt];
    lazy[rt] = 0;
    return;
}
void build(int l, int r, int rt) {
    if (l == r) {
        Min[rt] = f[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, rt * 2);
    build(mid + 1, r, rt * 2 + 1);
    Min[rt] = min(Min[rt * 2], Min[rt * 2 + 1]);
    return;
}
long long qmin(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) return Min[rt];
    pushdown(rt);
    int mid = (l + r) / 2;
    long long sum = 1e18;
    if (L <= mid) sum = min(sum, qmin(L, R, l, mid, rt * 2));
    if (R > mid) sum = min(sum, qmin(L, R, mid + 1, r, rt * 2 + 1));
    return sum;
}
void Update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && R >= r) {
        lazy[rt] += c, Min[rt] -= c;
        return;
    }
    int mid = (l + r) / 2;
    if (L <= mid) Update(L, R, c, l, mid, rt * 2);
    if (R > mid) Update(L, R, c, mid + 1, r, rt * 2 + 1);
    Min[rt] = min(Min[rt * 2], Min[rt * 2 + 1]);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        cin >> f[i];
    build(1, n - 1, 1);
    pair<int, int> p[N];
    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        if (l > r) swap(l, r);
        p[i] = {r, l};
    }
    sort(p, p + m);
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        int num = qmin(p[i].second + 1, p[i].first, 1, n - 1, 1);
        sum += num;
        Update(p[i].second + 1, p[i].first, num, 1, n - 1, 1);
    }
    cout << sum;
    return 0;
}