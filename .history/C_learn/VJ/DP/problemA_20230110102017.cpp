#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10000;
int dp[N][N];
int main(){
    string a , b;
    while(cin >> a >> b){
        a = " " + a;
        b = " " + b;
        int n = a.length() , m = b.length();
        dp[n][0] = 0; dp[0][m] = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(a[i] == b[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                }
            }
        }
        cout << dp[n][m] - 1 << endl;
    }
}


// //两种优化
// int DP[N] , w[N] , v[N];
// void solve(){
//     int n , m;
//     for(int i = 1 ; i <= n;i++){
//         for(int j = m ; j >= 0 ; j--){
//             if(w[i] <= j){
//                 DP[j] = max(DP[j], DP[j - w[i]] + v[i]);
//             }else continue;
//         }
//     }
// }
// int dp1[2][N];
// int solve1(){
//     int n , m;
//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 0 ; j <= m ;j++){
//             if(w[i] <= j){
//                 dp[i & 1][j] = max(dp[(i & 1) ^ 1][j] , dp[(i & 1) ^ 1][j - w[i]] + v[i]);
//             }else continue;
//         }
//     }
//     cout << dp[n & 1][m];
// }
