#include<iostream>
using namespace std;
long long num[100010] , sum[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n , m , k;
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++) cin >> sum[i];
    for(int i = 0 ; i < m;i++){
        int l , r , d;
        cin >> l >> r >> d;
        num[l] += d;
        num[r + 1] -= d;
    }
    for(int i = 0 ; i < k;i++){
        int a1 , a2;
        cin >> a1 >> a2;
    }
    for(int i = 1 ; i <= n ;i++){
        num[i] = num[i] + num[i - 1];
        sum[i] += num[i];
        cout << sum[i] << " ";
    }
}