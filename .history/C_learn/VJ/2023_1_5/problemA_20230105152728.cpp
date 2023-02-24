// #include <iostream>
// #include <unordered_map>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int ans = 0;
//     unordered_map<int , int> map1;
//     for(int i = 0; i < n ; i++){
//         int num;
//         cin >> num;
//         map1[num]++;
//     }
//     for(auto i : map1){
//         if(i.second == 1) ans++;
//         else ans += 2;
//     }
//     cout << ans << endl;
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n , num[100001] , ans = 0;
    cin >> n;
    vector<int> vec[100001];
    for(int i = 0 ; i< n ;i++) {
        cin >> num[i];
        vec[num[i]].push_back(i);
    }
    int p = 0 , q = 0;
    for(int i = 0 ; i < n ; i++){
        if(p == q){
            ans++;
            p = num[i];
        }else if(p == num[i]){
            q = num[i];
            ans++;
        }else if(q == num[i]){
            ans++;
            p = num[i];
        }else{

        }
    }
}