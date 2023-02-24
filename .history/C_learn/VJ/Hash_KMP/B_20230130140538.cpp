#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6 + 7;
const int Ha = 13331;
string s1, s2;
long long Hash1[N], Hash2[N], xp[N];
void Init() {
    xp[0] = 1;
    for (int i = 1; i < N; i++) {
        xp[i] = xp[i - 1] * Ha;
    }
}
void make_Hash(string s, long long Hash[]) {
    int len = s.length();
    Hash[len] = 0;
    for (int i = len - 1; i >= 0; i--) Hash[i] = (Hash[i + 1] * Ha + (s[i] - 'A' + 1));
}
int get_Hash(int n, int len, long long Hash[]) {
    return (Hash[n] - Hash[n + len] * xp[len]);
}
int main() {
    Init();
    int T;
    cin >> T;
    while (T--) {
        cin >> s1 >> s2;
        int ans = 0;
        make_Hash(s1, Hash1);
        make_Hash(s2, Hash2);
        int tmp = get_Hash(0, s1.length(), Hash1);
        for (int i = 0; i + s1.length() - 1 < s2.length(); i++)
            if (tmp == get_Hash(i, s1.length(), Hash2)) ans++;
        cout << ans << endl;
    }
}