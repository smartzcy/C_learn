#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
struct node {
    int l, r;
    int sum;
} seg[(N << 2)];
void up(int id) {
    // seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
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
    int mid = (seg[id].l + seg[id].r) >> 1;
}
int main() {
}