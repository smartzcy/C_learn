#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
struct node {
    int id;
    int num;
} seg[N];
bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        seg[i].id = i;
        cin >> seg[i].num;
    }
    sort(seg + 1, seg + n + 1, cmp);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cout << seg[i].id << " ";
        sum += seg[i].num * (n - i);
    }
    cout << endl;
    printf("%.2f", sum * 1.0 / n);
}