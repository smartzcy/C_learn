#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
long long s1[N] , s2[N] , num[N];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> num[i];
            s1[i] = 1e8;
            s2[i] = 1e8;
        }
        long long ans = 0;
        if(n % 2 == 1){
            for(int i = 2 ; i < n ;i += 2){
                ans += max(max(num[i + 1] , num[i - 1]) - num[i] + 1 , 0);
            }
        }else{
            int now = 0 , sum = 0;
            for(int i = 2 ; i < n ; i += 2){
                now += max(0 , max(num[i - 1] , num[i + 1]) - num[i] + 1);
                s1[i] = now;
            }
            for(int i = n - 1 ; i >= 2 ;i -= 2){
                sum += max(0 , max(num[i - 1] , num[i + 1]) - num[i] + 1);
                s2[i] = sum;
            }
            ans = min(s1[n - 2] , s2[3]);
            for(int i = 2 ; i + 3 < n ; i++){
                ans = min(ans , s1[i] + s2[i + 3]);
            }
        }
        cout << ans << endl;
    }
}
// (n - 2 + 1) / 2