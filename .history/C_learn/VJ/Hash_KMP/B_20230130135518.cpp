#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const int mod1 = 3145739;
string s1, s2;
struct Hash {
    ll has[N];
    ll bas[N];
    void init(string s) {
        s = "!" + s;
        ll p1 = 2333;
        has[0] = 0;
        bas[0] = 1;
        int len = s.length();
        for (int i = 1; i <= len; ++i) {
            bas[i] = (bas[i - 1] * p1) % mod1;
        }
        for (int i = 1; i <= len; ++i) {
            has[i] = (has[i - 1] * p1 + s[i]) % mod1;
        }
    }
    ll gethash(int r, int len) {
        return ((has[r] - has[r - len] * bas[len]) % mod1 + mod1) % mod1;
    }
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s1 >> s2;
        Hash h1, h2;
        h1.init(s1);
        h2.init(s2);
        int ans = 0, tmp = h1.gethash(1, s1.length());
        for (int i = 1; i + s1.length() <= s2.length(); ++i) {
            if (tmp == h2.gethash(i, s1.length())) ans++;
        }
        cout << ans << endl;
    }
}