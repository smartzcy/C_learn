#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int dp[N] , num[N];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> num[i];
            dp[i] = 0;
        }
        for(int i = 2 ; i < n ;i++){
            dp[i] = max(max(num[i + 1] , num[i - 1]) - num[i] + 1 , 0);
        }
        int m = (n - 2 + 1) / 2 , ans = 0;
        if(n % 2 == 1){
            for(int i = 2 ; i < n;i += 2){
                ans += dp[i];
            }
        }
        cout << ans << endl;
    }
}
// (n - 2 + 1) / 2