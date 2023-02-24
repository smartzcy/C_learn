#include<iostream>
#include<algorithm>
using namespace std;
const int N = 101;
long long a[N] , b[N] , c[N];
long long dp[2][N][N * N];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        dp[n & 1][1][n] = a[n];
        for(int i = n - 1 ; i >= 1 ;i--){
            for(int j = 0 ; j <= n;j++){
                for(int k = 0 ; k <= n * (n + 1) / 2 ;k++) dp[i & 1][j][k] = 0;
            }
            for(int j = n - i ; j >= 1 ;j--){
                for(int k = j * (2 * n - j + 1) / 2; k >= j * (i + 1 + i + 1 + j - 1) / 2;k--){
                    dp[i & 1][j + 1][k + i] = max(dp[i & 1][j + 1][k + i] , dp[(i & 1) ^ 1][j][k] + a[i]);
                    dp[i & 1][j][k] = max(dp[i & 1][j][k] , dp[(i & 1) ^ 1][j][k] + max((k - i * j) * b[i] , j * c[i]));
                }
            }
        }
        long long ans = 0;
        for(int i = 1 ; i <= n;i++){
            for(int j = 1 ; j <= n * (n + 1) / 2;j++){
                ans = max(ans , dp[1][i][j]);
            }
        }
        cout << ans << endl;
    }
}