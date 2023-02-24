// #include<iostream>
// #include<algorithm>
// using namespace std;
// bool cmp(const pair<int , int>& a, const pair<int , int>& b){
//     if(a.first == b.first) return a.second < b.second;
//     else return a.first > b.first;
// }
// int main(){
//     int n;
//     while(cin >> n , n != 0){
//         pair<int , int> num[100];
//         for(int i = 0 ; i < n ; i++)
//             cin >> num[i].first >> num[i].second;
//         sort(num , num + n , cmp);
//         int last = num[0].first , ans = 1;
//         for(int i = 1 ; i < n ;i++){
//             if(num[i].second <= last){
//                 last = num[i].first;
//                 ans++;
//             }
//         }
//         cout << ans << endl;
//     }
// }


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const pair<int , int>& a, const pair<int , int>& b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}
int main(){
    int n;
    while(cin >> n , n != 0){
        pair<int , int> num[100];
        for(int i = 0 ; i < n ; i++)
            cin >> num[i].first >> num[i].second;
        sort(num , num + n , cmp);
        int ans = 1;
        vector<int> vec;
        vec.push_back(num[0].first);
        for(int i = 1 , j ; i < n ;i++){
            for(j = 0 ; j < vec.size();j++){
                if(vec[j] >= num[i].second){
                    vec[j] = num[i].first;
                    break;
                }
            }
            if(j == vec.size()) {
                ans++;
                vec.push_back(num[i].first);
            }
        }
        cout << ans << endl;
    }
}