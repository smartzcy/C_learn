#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int m, q;
struct node {
    int l, r;
    int sum;
} seg[N << 2];
void up(int id) {
    seg[id].sum = max(seg[id << 1].sum, seg[id << 1 | 1].sum);
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
int main() {
    cin >> m >> q;
    while (m--) {
    }
}