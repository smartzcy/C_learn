#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int num[N];
bool check(int x) {
    int sum = 0;
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
    int l = 0, r = 0;
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
    cout << l << endl;
}