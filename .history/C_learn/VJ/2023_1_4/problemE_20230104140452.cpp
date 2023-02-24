#include<iostream>
using namespace std;
int num[100010] , sum[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++) cin >> sum[i];
    for(int i = 0 ; i < m;i++){
        int l , r , d;
        cin >> l >> r >> d;
        num[l] += d;
        num[r + 1] -= d;
    }
    for(int i = 0 ; i < k;i++){
        int nm;
        cin >> nm;
    }
    for(int i = 1 ; i <= n ;i++){
        num[i] = num[i] + num[i - 1];
        sum[i] += num[i];
        cout << sum[i] << " ";
    }
}