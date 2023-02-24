#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e4 + 1;
long long n, m, ans = 0;
int num[8] = {1, 6, 28, 88, 198, 328, 648};
int num2[8] = {8, 18, 28, 58, 128, 198, 388};
int dp[N];
int main() {
    cin >> n;
    for (int i = 0; i <= 6; i++) {
        for (int j = n; j >= 0; j--) {
            if (num[i] <= j) dp[j] = max(dp[j], dp[j - num[i]] + num2[i]);
        }
    }
    cout << dp[n] + n * 10 << endl;
}