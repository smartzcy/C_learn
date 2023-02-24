#include<iostream>
#include<algorithm>
using namespace std;
int n , m , V;
int dp[10010];
int w[10010] , v[10010];
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        V = m - n;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> v[i] >> w[i];
        }
        for(int i = 0 ; i <= V;i++) dp[i] = 0;
        for(int i = 0 ; i <= V;i++){
            for(int j = 1 ; j <= n;j++){
                if(w[j] <= i) dp[i] = max(dp[i - w[j]] + v[j] , dp[i - 1]);
            }
        }
        int ans = 0;
        for(int i = 0 ; i <= V ;i++){
            ans = max(ans , dp[i]);
        }
        cout << ans << endl;
    }
}