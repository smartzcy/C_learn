// #include <iostream>
// #include <algorithm>
// #include <map>
// using namespace std;
// map<int,int> map1;
// int now;
// int way(int k , int num , int sum){
//     if(now <= 0) return 0;
//     if(k <= 0) return 0;
//     int a1 = num * 2;
//     int a2 = num * 2 + 1;
//     now -= map1[a1] + map1[a2];
//     return min(map1[a1] + map1[a2] , k) * sum + way(k - map1[a1] + map1[a2] , a1 , sum + 1) + way(k - map1[a1] + map1[a2] , a2 , sum + 1);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n , k;
//     cin >> n >> k;
//     for(int i = 0 ; i < n ; i++){
//         int num;
//         cin >> num;
//         map1[num]++;
//     }
//     int min1 = 500000;
//     for(auto i : map1){
//         if(i.second >= k) {
//             min1 = 0;
//             break;
//         }
//         now = k - i.second;
//         min1 = min(min1 , way(now , i.second, 1));
//     }
//     cout << min1 << endl;
// }

#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int , pair<int,vector<pair<int,int>>> , greater<int>>map1;
    int n , k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        map1[num].first++;
    }
    int min1 = 1000000;
    for(auto i : map1){
        map1[i.first / 2].second.insert(map1[i.first / 2].second.begin(), {i.second.first , 1});
        int sum = 0 , num = k;
        num -= i.second.first;
        for(auto j : i.second.second){
            if(num > 0) {
                sum += min(num , j.first) * j.second;
                num -= j.first;
            }
            map1[i.first / 2].second.insert(map1[i.first / 2].second.begin() , {j.first, j.second + 1});
        }
        if(num <= 0) min1 = min(min1 , sum);
    }
    cout << min1;
}