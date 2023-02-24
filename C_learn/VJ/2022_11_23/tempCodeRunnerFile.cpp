#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string str[1001];
int dp[1001][1001];
int main(){
    memset(dp, 10000, sizeof(dp));
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str[i];
    }
    for(int i = 1 ; i <= n;i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i < m;i++){
        for(int j = 1 ; j <= n; j++){
            if(str[j][i] == '#'){
                dp[j][i] = 10000;
            }else{
                dp[j][i] = min(dp[j][i] , min(dp[j][i - 1] , min(dp[j - 1][i - 1] , dp[j + 1][i - 1])) + 1);
            }
            if(str[j][i] == '>'){
                for(int k = i + 1; k < m;k++){
                    if(str[j][k] == '.'){
                        dp[j][k] = min(dp[j][k] , dp[j][i] + 1);
                        break;
                    }else if(str[j][k] == '>'){
                        dp[j][k] = min(dp[j][k] , dp[j][i] + 1);
                        continue;
                    }
                }
            }
        }
    }
    for(int i = 1 ; i <= n;i++){
        for(int j = 0 ; j < m;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int min1 = 10000;
    for(int i = 1 ; i <= n;i++){
        min1 = min(min1 , dp[i][m - 1]);
    }
    cout << min1;
}