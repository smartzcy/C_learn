#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int num[N];
int dp[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + (num[i] - num[j]) * (num[i] - num[j]));
        }
    }
    cout << dp[n] << endl;
}