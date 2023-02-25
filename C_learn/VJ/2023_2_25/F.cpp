#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
long long dp[N][3];
int n, m;
int main() {
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    long long temp = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) dp[i][j] = dp[i - 1][j] % mod;
        if (str[i] == 'a')
            dp[i][0] = (dp[i - 1][0] % mod + temp) % mod;
        else if (str[i] == 'b')
            dp[i][1] = (dp[i - 1][1] % mod + dp[i - 1][0] % mod) % mod;
        else if (str[i] == 'c')
            dp[i][2] = (dp[i - 1][2] % mod + dp[i - 1][1] % mod) % mod;
        else if (str[i] == '?') {
            dp[i][0] = (3 * dp[i - 1][0] % mod + temp) % mod;
            dp[i][1] = (3 * dp[i - 1][1] % mod + dp[i - 1][0] % mod) % mod;
            dp[i][2] = (3 * dp[i - 1][2] % mod + dp[i - 1][1] % mod) % mod;
            temp = (temp * 3) % mod;
        }
    }
    cout << dp[n][2] << endl;
}