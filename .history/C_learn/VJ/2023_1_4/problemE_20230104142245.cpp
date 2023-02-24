#include<iostream>
using namespace std;
long long num[100010] , sum[100010];
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
    for(int i = 1 ; i <= m;i++){
        cin >> opt[i].l >> opt[i].r >> opt[i].val;
    }
    for(int i = 0 ; i < k;i++){
        int l , r;
        cin >> l >> r;
        while(l <= r){
            num[opt[l].l] += opt[l].val;
            num[opt[l].r + 1] -= opt[l].val;
            l++;
        }
    }
    for(int i = 1 ; i <= n ;i++){
        num[i] = num[i] + num[i - 1];
        sum[i] += num[i];
        cout << sum[i] << " ";
    }
    return 0;
}