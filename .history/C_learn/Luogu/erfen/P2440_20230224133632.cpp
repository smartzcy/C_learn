#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
long long num[N];
bool check(int x) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += num[i] / x;
    }
    if (sum >= m)
        return true;
    else
        return false;
}
int main() {
    cin >> n >> m;
    long long l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        r = max(r, num[i]);
    }
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1 << endl;
}