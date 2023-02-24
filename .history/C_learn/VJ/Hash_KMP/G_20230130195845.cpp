#include <iostream>
using namespace std;
const int N = 1e5;
int Next[N];
int get_Hash(string s) {
    int j = 0, k = -1;
    Next[0] = -1;
    while (j < s.length()) {
        if (k == -1 || s[k] == s[j])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
    return Next[s.length()];
}
int main() {
    int n;
    cin >> n;
    string ans;
    cin >> ans;
    n--;
    while (n--) {
        string str;
        cin >> str;
        // cout << get_Hash(str + ans) << endl;
        ans = ans.substr(0, ans.length() - get_Hash(str + ans)) + str;
    }
    cout << ans << endl;
}