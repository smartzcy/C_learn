#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e6;
int n, m;
ll num[N], numr[N], p[N], mod = 133331;
ll get(ll l, ll r) {
    return num[r] - num[l] * p[r - l];
}
ll getr(ll l, ll r) {
    return numr[r] - numr[l] * p[l - r];
}
bool check(ll x, ll i) {
    return get(i - x, i) == getr(i + 1 + x, i + 1);
}
ll bs1(ll l, ll r, ll i) {
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(mid, i))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
int main() {
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        num[i] = num[i - 1] * mod + str[i];
        p[i] = p[i - 1] * mod;
    }
    for (int i = n; i >= 1; i--) {
        char c;
        if (str[i] == '1')
            c = '0';
        else
            c = '1';
        numr[i] = numr[i + 1] * mod + c;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] != str[i + 1]) ans += bs1(0, min(i, n - i), i);
    }
    cout << ans << endl;
}