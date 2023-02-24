#include <iostream>
#include <algorithm>
using namespace std;
// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         int n , k , ans = 0 , num = 0 , cnt = 0;
//         cin >> n >> k;
//         string str;
//         cin >> str;
//         for(int i = 0 ; i < str.length() ; i++){
//             if(str[i] == '1'){
//                 cnt++;
//                 n = i;
//             }
//         }
//         for(int i = 0 ; i <= n;i++){
//             if(num != 0){
//                 if(i == num){
//                     if(str[i] == '0') ans++;
//                     num += k;
//                 }else{
//                     ans += str[i] - '0';
//                 }
//             }else if(str[i] == '1') num = i + k;
//         }
//         cout << min(ans , cnt) << endl;
//     }
//     return 0;
// }

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        for (auto i : s) cnt += i - '0';
        int ans = 2e18;
        int ma = 0;
        for (int i = 0; i < k; i++){
            int sum = 0;
            for (int j = i; j < n; j += k){
                if (s[j] == '1') sum++;
                else sum--;
                sum = max(0 , sum);
                ma = max(ma , sum);
            }
        }
        cout << cnt - ma << endl;
    }
    return 0;
}