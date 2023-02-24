#include<iostream>
#include<vector>
using namespace std;
long long num[100010] , sum[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<pair<int,int> , int>> vec;
    long long n , m , k;
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++) cin >> sum[i];
    for(int i = 0 ; i < m;i++){
        int l , r , d;
        cin >> l >> r >> d;
        vec.push_back({{l , r} , d});
    }
    for(int i = 0 ; i < k;i++){
        int l , r;
        cin >> l >> r;
        while(l <= r){
            num[vec[l - 1].first.first] += vec[l - 1].second;
            num[vec[l - 1].first.second + 1] -= vec[l - 1].second;
            l++;
        }
    }
    for(int i = 1 ; i <= n ;i++){
        num[i] = num[i] + num[i - 1];
        sum[i] += num[i];
        cout << sum[i] << " ";
    }
}