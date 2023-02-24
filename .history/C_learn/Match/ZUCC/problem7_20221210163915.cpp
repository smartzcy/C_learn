// #include<iostream>
// #include<set>
// using namespace std;
// set<pair<int,int> > s;
// int n , k;
// void way(int a , int b){
//     s.insert({a , b});
//     s.insert({a + 1 , b});
//     s.insert({a + 1 , b + 1});
//     if(a + 1 == n) return ;
//     way(a + 1 , b);
//     way(a + 1 , b + 1);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> k;
//     for(int i = 0 ; i < k;i++){
//         int a , b;
//         cin >> a >> b;
//         way(a , b);
//         if(s.find({a , b - 1}) != s.end()){
//             s.insert({a - 1 , b - 1});
//         }else if(s.find({a , b + 1}) != s.end()){
//             s.insert({a - 1 , b});
//         }
//     }
//     cout << s.size();
// }

// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n , k;
//     cin >> n >> k;
//     int x = 0 , y = 0;
//     for(int i = 0 ; i < k ; i++){
//         int a , b;
//         cin >> a >> b;
//         if(x == 0){
//             x = a;
//             y = b;
//         }else{
//             int flag = 0;
//             if(y < b){
//                 if(y + (n - x) >= b - (n - a)) flag = 1;
//             }else{
//                 if(y - (n - x) <= b + (n - a)) flag = 1;
//             }
//             if(flag == 1){
//                 x -= abs(y - b);
//                 y = min(y , b);
//             }
//         }
//     }
//     int num = n - x + 1;
//     cout << (num + 1) * num / 2;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> merge(vector<pair<int,int>> &segs){
    vector<pair<int,int>> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed <= seg.first - 1){
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }else ed = max(ed, seg.second);
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}
int main(){
    vector<pair<int,int>>vec;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n >> k;
    for(int i = 0 ; i < k;i++){
        int a , b;
        cin >> a >> b;
        vec.push_back({b , b + (n - a)});
    }
    vec = merge(vec);
    int sum = 0;
    for(auto i : vec){
        cout << i.first << " " << i.second << endl;
        sum += (i.second - i.first + 1 + 1) * (i.second - i.first + 1) / 2;
    }
    cout << sum;
}
