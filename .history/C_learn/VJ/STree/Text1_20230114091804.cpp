#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
struct node {
    int l, r;
    int sum;
} seg[(N << 2)];
void up(int id) {
    seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
}
void build(int id, int l, int r) {
    if (l == r) {
        seg[id].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
int main() {
}