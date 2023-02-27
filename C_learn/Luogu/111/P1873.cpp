#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int num[N];
bool check(int x) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max(0, num[i] - x);
    }
    // cout << x << " " << sum << endl;
    if (sum >= m)
        return true;
    else
        return false;
}
int main() {
    cin >> n >> m;
    int maxH = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        maxH = max(maxH, num[i]);
    }
    int l = 0, r = maxH;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1 << endl;
}