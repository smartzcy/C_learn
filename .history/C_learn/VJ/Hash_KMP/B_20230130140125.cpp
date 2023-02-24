#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5;
const int Ha = 13331;
string s1, s2;
int Hash1[N], Hash2[N], xp[N];
void Init() {
    xp[0] = 1;
    for (int i = 1; i < N; i++) {
        xp[i] = xp[i - 1] * Ha;
    }
}
void make_Hash(string s, int Hash[]) {
    int len = s.length();
    Hash[len] = 0;
    for (int i = len - 1; i >= 0; i--) Hash[i] = (Hash[i + 1] * Ha + (s[i] - 'A' + 1));
}
int get_Hash(int n, int len, int Hash[]) {
    return (Hash[n] - Hash[n + len] * xp[len]);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s1 >> s2;
    }
}