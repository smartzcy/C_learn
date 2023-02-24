#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int m, q;
struct node {
    int l, r;
    int sum;
} seg[N << 2];
void change(int id, int pos, int val) {
    if (seg[id].l == seg[id].r) {
        seg[id].sum = max(seg[id].sum, val);
        return;
    }
}
int main() {
    cin >> m >> q;
    while (m--) {
    }
}