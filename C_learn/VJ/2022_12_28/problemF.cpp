#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , ans = 0;
        string s;
        cin >> n >> s;
        for(int i = 0 ; i < n;i++){
            int sum1 = 0 , sum2 = 0;
            for(int j = i ; j < n;j++){
                if(s[j] == '+') sum1++;
                else sum2++;
                if(sum1 == sum2) ans++;
                int k = (sum2 - sum1) / 3;
                if(sum2 > sum1 && sum1 + k == sum2 - 2 * k) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}