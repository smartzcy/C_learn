// #include <iostream>
// using namespace std;
// const int N = 1e5;
// int Next[N];
// int get_Hash(string s) {
//     int j = 0, k = -1;
//     Next[0] = -1;
//     while (j < s.length()) {
//         if (k == -1 || s[k] == s[j])
//             Next[++j] = ++k;
//         else
//             k = Next[k];
//     }
//     return Next[s.length()];
// }
// int main() {
//     int n;
//     cin >> n;
//     string ans , str;
//     cin >> ans;
//     n--;
//     while (n--) {
//         cin >> str;
//         ans = ans.substr(0, ans.length() - get_Hash(str + ans)) + str;
//     }
//     cout << ans << endl;
// }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int MAXN = 1e6 + 7;
char s[MAXN], t[MAXN];
int Next[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int now = strlen(s + 1);
    for (int c = 2; c <= n; c++) {
        scanf("%s", t + 1);
        int m = strlen(t + 1);
        Next[0] = Next[1] = 0;
        int j = 0;
        for (int i = 2; i <= m; i++) {
            while (j && t[i] != t[j + 1]) j = Next[j];
            if (t[i] == t[j + 1]) ++j;
            Next[i] = j;
        }
        j = 0;
        for (int i = max(now - m + 1, 1); i <= now; i++) {
            while (j && s[i] != t[j + 1]) j = Next[j];
            if (s[i] == t[j + 1]) ++j;
        }
        for (++j; j <= m; ++j) s[++now] = t[j];
    }
    puts(s + 1);
    return 0;
}
