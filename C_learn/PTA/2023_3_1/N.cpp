#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int n, m;
long long dp[N][4];
int main() {
    string str;
    cin >> str;
    str = " " + str;
    long long ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i < str.length(); i++) {
        for (int j = 0; j <= 3; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j) dp[i][j] += dp[i - 1][j - 1];
            for (int k = i - 1; k >= 1 && i - k <= j; k--) {
                if (str[k] == str[i]) {
                    dp[i][j] -= dp[k - 1][j - (i - k)];
                    break;
                }
            }
        }
    }
    for (int i = 0; i <= 3; i++) ans += dp[str.length() - 1][i];
    cout << ans << endl;
}