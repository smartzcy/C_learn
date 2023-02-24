#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const pair<int , int>& a, const pair<int , int>& b){
    return a.second > b.second;
}
int main(){
    pair<int , int> num[200000];
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i< n ;i++)
        cin >> num[i].first >> num[i].second;
    sort(num , num + n , cmp);
    int ans = 0;
    int l = num[0].second;
    for(int i = 0 ; i < n ; i++){
        int k = i + 1;
        while(l + m >= num[k].first) k++;
        ans++;
        i = k - 1;
        l = num[k].second;
    }
    cout << ans << endl;
}