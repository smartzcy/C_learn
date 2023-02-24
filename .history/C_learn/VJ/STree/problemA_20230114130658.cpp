#include <iostream>
using namespace std;
int n, q;
const int N = 1e5;
struct node {
    int l, r;
    int sum;
} seg[N << 2];
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) seg[id].sum = a[l];
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
    }
}