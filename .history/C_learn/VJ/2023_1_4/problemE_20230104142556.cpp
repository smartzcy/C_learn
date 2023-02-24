#include<iostream>
using namespace std;
long long num[100010] , sum[100010] , cnt[100010];
struct node{
    long long l , r , val;
}opt[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n , m , k;
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++) cin >> sum[i];
    for(int i = 1 ; i <= m;i++) cin >> opt[i].l >> opt[i].r >> opt[i].val;
    for(int i = 0 ; i < k;i++){
        int l , r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    for(int i = 1 ; i <= m;i++){
        cnt[i] += cnt[i - 1];
        num[opt[i].l] += opt[i].val * cnt[i];
        num[opt[i].r + 1] -= opt[i].val * cnt[i];
    }
    for(int i = 1 ; i <= n ;i++){
        num[i] = num[i] + num[i - 1];
        sum[i] += num[i];
        cout << sum[i] << " ";
    }
    return 0;
}