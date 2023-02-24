#include <iostream>
using namespace std;
const int N = 1e5;
int Next[N];
void get_Hash(string s) {
    int j = 0, k = -1;
    Next[0] = -1;
    while (j < s.length()) {
        if (k == -1 || s[k] == s[j])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
}
int main() {
    string str = "twat";
    get_Hash(str);
    for (int i = 0; i <= str.length(); i++) {
        cout << Next[i] << endl;
    }
    // int n;
    // cin >> n;
    // string ans;
    // cin >> ans;
    // n--;
    // while (n--) {
    //     string str;
    //     cin >> str;
    //     cout << get_Next(str + ans) << endl;
    //     ans = ans.substr(0, ans.length() - get_Next(str + ans)) + str;
    // }
    // cout << ans << endl;
}