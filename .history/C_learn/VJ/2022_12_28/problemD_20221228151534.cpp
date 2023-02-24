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


#include<iostream>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long n , a[200011] , max = 0;
        map<int , int> map1;
        map1[0] = 0;
        a[0] = 0;
        cin >> n;
        int x = n , y = 0;
        for(int i = 1 ; i <= n;i++){
            cin >> a[i];
            if(a[i] == 0){
                map1.clear();
                a[i] = 0;
            }else{
                if(a[i] == 2){
                    if(a[i - 1] >= 0) a[i] = a[i - 1] + 1;
                    else a[i] = a[i - 1] - 1;
                }else if(a[i] == -2){
                    if(a[i - 1] >= 0) a[i] = -a[i - 1] - 1;
                    else a[i] = -a[i - 1] + 1;
                }else if(a[i] == -1){
                    a[i] = -a[i - 1];
                }else if(a[i] == 1) a[i] = a[i - 1];
            }
            if(a[i] > 0 && map1.size() >= 1){
                map<int,int>::iterator it = map1.lower_bound(0);
                cout << a[i] << endl;
                if(a[i] - it->first > max){
                    max = a[i] - it->first;
                    x = it->second;
                    y = n - i;
                }else if(it == map1.end()){
                    if(a[i] > max){
                        max = a[i];
                        x = 0;
                        y = n - i;
                    }
                }
            }else if(a[i] > 0 && map1.size() == 0){
                if(a[i] > max){
                    max = a[i];
                    x = 0;
                    y = n - 1;
                }
            }else if(a[i] < 0 && map1.size() >= 1){
                map<int , int>::iterator it = map1.lower_bound(0);
                it--;
                if(abs(a[i]) - abs(it->first) > max){
                    max = -a[i] + it->first;
                    x = it->second;
                    y = n - i;
                }
            }
            map1[a[i]] = i;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}