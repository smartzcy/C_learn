#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> vec;
// int FindDeep(int n){
//     if(vec[n - 1].first == 0 && vec[n - 1].second == 0) return 1;
//     return max(FindDeep(vec[n - 1].first), FindDeep(vec[n - 1].second)) + 1;
// }
int ans;
void dfs(int id , int deep){
    if(id == 0) return;
    ans = max(ans , deep);
    dfs(vec[id - 1].first, deep + 1);
    dfs(vec[id - 1].second, deep + 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1 ;  i <= n;i++){
        int a , b;
        cin >> a >> b;
        vec.push_back(pair<int,int>(a,b));
    }
    // cout << FindDeep(1);
    dfs(1 , 1);
    cout << ans;
    return 0;
}