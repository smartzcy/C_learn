#include <iostream>
using namespace std;
const int N = 1e5;
int Next[N];
int get_Next(string str) {
    int j = 0, k = -1;
    Next[0] = -1;
    while (j < str.length()) {
        if (k == -1 || str[k] == str[j])
            Next[++j] == ++k;
        else
            k = Next[k];
    }
    return Next[str.length()];
}
int main() {
    string str = "tawt";
    cout << get_Next(str) << endl;
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