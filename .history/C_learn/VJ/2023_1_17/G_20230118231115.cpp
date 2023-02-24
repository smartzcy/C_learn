#include <iostream>
#include <algorithm>
using namespace std;
long long n, min1, min2;
const int N = 1e5;
struct node {
    long long v, t2, t3;
} a[N];
int main() {
    min1 = 0x3f3f3f3f;
    min2 = 0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].v;
    for (int i = 0; i < n; i++) {
        if (a[i].v % 2 == 0 || a[i].v % 3 == 0) {
            while (a[i].v % 2 == 0) {
                a[i].v /= 2;
                a[i].t2++;
            }
            while (a[i].v % 3 == 0) {
                a[i].v /= 3;
                a[i].t3++;
            }
            min1 = min(min1, a[i].t2);
            min2 = min(min2, a[i].t3);
        }
    }
    long long ans = a[0].t2 + a[0].t3 - min1 - min2;
    int num = a[0].v;
    for (int i = 1; i < n; i++) {
        if (num != a[i].v) {
            cout << "-1" << endl;
            return 0;
        }
        ans += a[i].t2 + a[i].t3 - min1 - min2;
    }
    cout << ans << endl;
}