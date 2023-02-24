#include<iostream>
using namespace std;
int main(){
    int n;
    int number = 1;
    while (cin >> n , n != 0){
        int num[333][333] = {{0}};
        int m[2200];
        int Max_H = 0;
        int Max_L = 0;
        for(int i = 0 ; i < n ; i++){
            int x , y;
            cin >> x >> y;
            Max_H = Max_H > x ? Max_H : x;
            Max_L = Max_L > y ? Max_L : y;
            m[2 * i] = x;
            m[2 * i + 1] = y;
            num[x][y] = 1;
        }
        cout << "Case " << number++ << ":" << endl;
        for(int i = 0; i < n;i++){
            if(m[2 * i] == Max_H || m[2 * i + 1] == Max_L){
                cout << -1 << " " << -1 << endl;
            }else{
                int nm = 0;
                for(int j = m[2 * i] + 1; j <= Max_H;++j){
                    for(int k = m[2 * i + 1] + 1 ; k <= Max_L;++k){
                        if(num[j][k] == 1){
                            cout << j << " " << k << endl;
                            nm = 1;
                            break;
                        }
                    }
                if(nm) break;
                }
            if(nm == 0) cout << -1 << " " << -1 << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <map>
// #include <queue>
// #include <stack>
// #include <queue>
// #include <iostream>
// #include <cmath>
// #include <cstring>
// #include <set>
// #include <iomanip>
// #include <stdexcept>
// #include <fstream>
// using namespace std;
// int cnt = 1;
// int x[1010];
// int y[1010];
// int a[333][333];
// int main() {
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     int n;
//     while (cin >> n) {
//         if (n == 0) break;
//         memset(x, 0, sizeof(x));
//         memset(y, 0, sizeof(y));
//         memset(a, 0, sizeof(a));
//         int mx1 = 0;
//         int mx2 = 0;
//         for (int i = 1; i <= n; ++i) {
//             cin >> x[i] >> y[i];
//             a[x[i]][y[i]] = 1;
//             mx1 = max(mx1, x[i]);
//             mx2 = max(mx2, y[i]);
//             // cout<<i<<endl;
//         }
//         cout << "Case " << cnt++ << ":" << endl;
//         for (int i = 1; i <= n; ++i) {
//             int l = x[i], r = y[i];
//             if (l == mx1 || r == mx2) {
//                 cout << -1 << " " << -1 << endl;
//                 continue;
//             }
//             int flag = 0;
//             for (int j = l + 1; j <= mx1; ++j) {
//                 for (int k = r + 1; k <= mx2; ++k) {
//                     if (a[j][k]) {
//                         cout << j << " " << k << endl;
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if (flag) break;
//             }
//             if(flag == 0)cout << -1 << " " << -1 << endl;
//         }
//         cout << endl;
//     }
// }