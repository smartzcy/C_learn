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
// void merge(vector<pair<int,int>> &segs){
//     vector<pair<int,int>> res;
//     sort(segs.begin(), segs.end());
//     int st = -2e9, ed = -2e9;
//     for (auto seg : segs)
//         if (ed < seg.first){
//             if (st != -2e9) res.push_back({st, ed});
//             st = seg.first, ed = seg.second;
//         }
//         else ed = max(ed, seg.second);
//     if (st != -2e9) res.push_back({st, ed});
//     segs = res;
// }
static bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
vector<pair<int, int>> merge(vector<pair<int, int>> &intervals){
    if (intervals.size() <= 1)
        return intervals; // 集合为空或者为一个区间
    vector<pair<int, int>> res;
    sort(intervals.begin(), intervals.end(), cmp); // 排序，规定使用这种按start升序排列
    int i = 0;
    pair<int, int> temp = {intervals[0].first, intervals[0].second}; // 赋初值，temp为组合新的区间
    while (i < intervals.size()){
        temp.first = intervals[i].first;
        temp.second = intervals[i].second;
        while (i < intervals.size()){
            if (i < intervals.size() - 1 && temp.second >= intervals[i + 1].first) // 防止数组访问越界i < intervals.size()-1；前后区间有交集
            {
                if (temp.second < intervals[i + 1].second) // 后面的区间没有包含进来
                {
                    temp.second = intervals[i + 1].second; // 将后面区间合并成更大的区间
                }
                i++;
            }
            else // 前后区间没有交集
            {
                i++;
                break;
            }
        }
        res.push_back(temp);
    }
    return res;
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
    merge(vec);
    int sum = 0;
    for(auto i : vec){
        cout << i.first << " " << i.second << endl;
        sum += (i.second - i.first + 1 + 1) * (i.second - i.first + 1) / 2;
    }
    cout << sum;
}
