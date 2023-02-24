#include<iostream>
#include<algorithm>
using namespace std;
const int N = 101;
int a[N] , b[N] , c[N];
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
            for(int j = 1 ; j <= n - i ;j++){
                for(int k = (i * 2 + j) * (j - 1) / 2 + n ; k <= (2 * n - j + 1) * j / 2 ;k++){
                    dp[i & 1][j + 1][k + i] = max(dp[i & 1][j + 1][k + i] , dp[(i + 1) & 1][j][k] + a[i]);
                    dp[i & 1][j][k] = max(dp[i & 1][j][k] , max(dp[(i + 1) & 1][j][k] + (k - i * j) * b[i] , dp[(i + 1) & 1][j][k] + j * c[i]));
                }
            }
        }
        long long ans = 0;
        for(int i = 1 ; i <= n;i++){
            for(int j = 1 ; j <= 5050;j++){
                ans = max(ans , dp[1][i][j]);
            }
        }
        cout << ans << endl;
    }
}