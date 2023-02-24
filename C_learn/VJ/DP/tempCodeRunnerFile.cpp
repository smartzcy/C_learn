#include<iostream>
#include<algorithm>
using namespace std;
int n , V;
int v[1001] , w[1001];
int dp[1010];
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> V;
        for(int i = 1 ; i <= n ; i++){
            cin >> v[i];
        }
        for(int i = 1 ; i <= n ; i++){
            cin >> w[i];
        }
        for(int i = 0 ; i <= V ; i++) dp[i] = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = V ; j >= 0 ; j--){
                if(w[i] <= j){
                    dp[j] = max(dp[j] , dp[j - w[i]] + v[i]);
                }else continue;
            }
        }
        cout << dp[V] << endl;
    }
}