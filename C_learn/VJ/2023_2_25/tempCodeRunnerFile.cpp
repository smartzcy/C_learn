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
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'a')
            dp[i][0] = (dp[i - 1][0] + temp) % mod;
        else if (str[i] == 'b')
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
        else if (str[i] == 'c')
            dp[i][2] = (dp[i - 1][2] + dp[i - 1][1]) % mod;
        else if (str[i] == '?') {
            dp[i][0] = (3 * dp[i - 1][0] + temp) % mod;
            dp[i][1] = (3 * dp[i - 1][1] + dp[i - 1][0]) % mod;
            dp[i][2] = (3 * dp[i - 1][2] + dp[i - 1][1]) % mod;
            temp = temp * 3 % mod;
        }
    }
    cout << dp[n][2] << endl;
}