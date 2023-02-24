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
        for(int i = 0 ; i <= V;i++) dp[i] = -1;
        dp[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = w[i] ; j <= V;j++){
                dp[j] = min(dp[j] , dp[j - w[i]] + v[i]);
            }
        }
        if(dp[V] == -1) cout << "This is impossible." << endl;
        else cout << "The minimum amount of money in the piggy-bank is " << dp[V] << "." << endl;
    }
}