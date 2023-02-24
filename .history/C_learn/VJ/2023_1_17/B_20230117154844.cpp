#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
int a[N], b[N], c[N];
struct node {
    int l, r;
    int sum;
    node *left;
    node *right;
    node(int l, int r, int sum) :
        l(l), r(r), sum(sum), left(NULL), right(NULL) {
    }
};
node *build(int l, int r) {
    if (l > r) return NULL;
    if (l == r) {
        return new node(l, r, 0);
    }
    node *root = new node(l, r, 0);
    int mid = (l + r) >> 1;
    root->left = build(l, mid);
    root->right = build(mid + 1, r);
    return root;
}
int query(node *root, int l, int r) {
    if (l <= root->l && root->r <= r) {
        return root->sum;
    }
    int mid = (root->l + root->r) >> 1;
    int ans = 0;
    if (l <= mid) ans += query(root->left, l, r);
    if (mid < r) ans += query(root->right, l, r);
    return ans;
}
void modify(node *root, int pos, int val) {
    if (root->l == root->r && root->l == pos) {
        root->sum += val;
        return;
    }
    int mid = (root->l + root->r) >> 1;
    if (pos <= mid)
        modify(root->left, pos, val);
    else
        modify(root->right, pos, val);
    root->sum = root->left->sum + root->right->sum;
}
node *root;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    root = build(0, 10000);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        int ans = k * a[i] - c[k] + (query(root, 0, a[i]));
        modify(root, a[i], 1);
        cout << ans << endl;
    }
}