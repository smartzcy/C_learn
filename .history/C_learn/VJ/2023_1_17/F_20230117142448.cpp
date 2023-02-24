#include <iostream>
using namespace std;
const int N = 5e3 + 10;
int dp[N][N];
int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    dp[n][0] = 0;
    dp[0][m] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
            }
        }
    }
    cout << dp[n][m] << endl;
}