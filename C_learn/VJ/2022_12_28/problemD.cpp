// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     cin >> T;
//     while(T--){
//         long long n , a[200011] , max = 1;
//         map<int , int> map1;
//         map1[1] = 0;
//         a[0] = 1;
//         cin >> n;
//         int x = n , y = 0;
//         for(int i = 1 ; i <= n;i++){
//             cin >> a[i];
//             if(a[i] == 0){
//                 map1.clear();
//                 a[i] = 1;
//             }else{
//                 a[i] = a[i] * a[i - 1];
//             }
//             if(a[i] > 0 && map1.size() >= 1){
//                 map<int,int>::iterator it = map1.upper_bound(0);
//                 if(a[i] / it->first > max){
//                     max = a[i] / it->first;
//                     x = it->second;
//                     y = n - i;
//                 }else if(it == map1.end()){
//                     if(a[i] > max){
//                         max = a[i];
//                         x = 0;
//                         y = n - i;
//                     }
//                 }
//             }else if(a[i] > 0 && map1.size() == 0){
//                 if(a[i] > max){
//                     max = a[i];
//                     x = 0;
//                     y = n - 1;
//                 }
//             }else if(a[i] < 0 && map1.size() >= 1){
//                 map<int , int>::iterator it = map1.lower_bound(0);
//                 it--;
//                 if(a[i] / it->first > max){
//                     max = a[i] / it->first;
//                     x = it->second;
//                     y = n - i;
//                 }
//             }
//             map1[a[i]] = i;
//         }
//         cout << x << " " << y << endl;
//     }
//     return 0;
// }

// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     cin >> T;
//     while(T--){
//         long long n , a[200011] , max = 0;
//         map<int , int> map1;
//         map1[0] = 0;
//         a[0] = 0;
//         cin >> n;
//         int x = n , y = 0;
//         for(int i = 1 ; i <= n;i++){
//             cin >> a[i];
//             if(a[i] == 0){
//                 map1.clear();
//                 a[i] = 0;
//             }else{
//                 if(a[i] == 2){
//                     if(a[i - 1] >= 0) a[i] = a[i - 1] + 1;
//                     else a[i] = a[i - 1] - 1;
//                 }else if(a[i] == -2){
//                     if(a[i - 1] >= 0) a[i] = -a[i - 1] - 1;
//                     else a[i] = -a[i - 1] + 1;
//                 }else if(a[i] == -1){
//                     a[i] = -a[i - 1];
//                 }else if(a[i] == 1) a[i] = a[i - 1];
//             }
//             if(a[i] > 0 && map1.size() >= 1){
//                 map<int,int>::iterator it = map1.lower_bound(0);
//                 if(a[i] - it->first > max){
//                     max = a[i] - it->first;
//                     x = it->second;
//                     y = n - i;
//                 }else if(it == map1.end()){
//                     if(a[i] > max){
//                         max = a[i];
//                         x = 0;
//                         y = n - i;
//                     }
//                 }
//             }else if(a[i] > 0 && map1.size() == 0){
//                 if(a[i] > max){
//                     max = a[i];
//                     x = 0;
//                     y = n - 1;
//                 }
//             }else if(a[i] < 0 && map1.size() >= 1){
//                 map<int , int>::iterator it = map1.lower_bound(0);
//                 if(it == map1.begin()) continue;
//                 it--;
//                 if(abs(a[i]) - abs(it->first) > max){
//                     max = -a[i] + it->first;
//                     x = it->second;
//                     y = n - i;
//                 }
//             }
//             map1[a[i]] = i;
//         }
//         cout << x << " " << y << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
const int maxj = 2e5 + 100;
int a[maxj];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int sum[maxj] = {0}, sum2[maxj] = {0}, ans = 0, ansl = 1, ansr = 0;
        int n;
        cin >> n;
        sum[0] = 0, sum2[0] = 0;
        for(int i = 1 ; i <= n; ++i){
            cin >> a[i];
            sum[i] = sum[i - 1] + (a[i] < 0 ? 1 : 0);
            sum2[i] = sum2[i - 1] + (abs(a[i]) == 2 ? 1 : 0);
        }
        int l = 1, r = 0;
        while (l <= n){
            while (a[l] == 0 && l <= n) l++;
            if (l > n) break;
            r = l;
            while (r <= n && a[r] != 0) r++;
            r--;
            if ((sum[r] - sum[l - 1]) % 2 == 0){
                if (sum2[r] - sum2[l - 1] > ans){
                    ans = sum2[r] - sum2[l - 1];
                    ansl = l, ansr = r;
                }
            }
            else{
                int pre = l, las = r;
                while (pre <= n && a[pre] > 0) pre++;
                while (las <= n && a[las] > 0) las--;
                if (sum2[r] - sum2[pre] > ans){
                    ans = sum2[r] - sum2[pre], ansl = pre + 1;
                    ansr = r;
                }
                if (sum2[las - 1] - sum2[l - 1] > ans){
                    ans = sum2[las - 1] - sum2[l - 1];
                    ansl = l, ansr = las - 1;
                }
            }
            l = r + 1;
        }
        cout << ansl - 1 << ' ' << n - ansr << '\n';
    }
    return 0;
}