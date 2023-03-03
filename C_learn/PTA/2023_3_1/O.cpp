#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5;
int n, m;
struct node {
    long long x, y;
    int rel;
} a[N], b[N];
bool cmp(const node &a, const node &b) {
    if (a.rel != b.rel) return a.rel < b.rel;
    return a.x * b.y - a.y * b.x < 0;
}
int judge(node x) {
    if (x.x > 0 && x.y > 0)
        return 1;
    else if (x.x < 0 && x.y > 0)
        return 4;
    else if (x.x > 0 && x.y < 0)
        return 2;
    else if (x.x < 0 && x.y < 0)
        return 3;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    double ans = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            b[cnt].x = a[j].x - a[i].x;
            b[cnt].y = a[j].y - a[i].y;
            b[cnt].rel = judge(b[cnt]);
            cnt++;
        }
        sort(b + 1, b + n, cmp);
        for (int j = 1; j < n - 1; j++) {
            if (ans == -1 || fabs(b[j + 1].x * b[j].y - b[j + 1].y * b[j].x) * 0.5 < ans)
                ans = fabs(b[j + 1].x * b[j].y - b[j + 1].y * b[j].x) * 0.5;
        }
    }
    printf("%.3f", ans);
}