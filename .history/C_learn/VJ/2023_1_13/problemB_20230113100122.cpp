#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n , q;
long long a[N];
int lowbit(int x){
    return x & -x;
}
long long getsum(int x){
    long long sum = 0;
    while(x > 0){
        sum += a[x];
        x -= lowbit(x);
    }
    return sum;
}
void add(int x , int val){
    while(x <= n){
        a[x] += val;
        x += lowbit(x);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    int pre = 0;
    for(int i = 1 ; i <= n ; i++){
        int num;
        cin >> num;
        add(i , num - pre);
        pre = num;
    }
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int l , r , x;
            cin >> l >> r >> x;
            add(l , x);
            add(r + 1 , -x);
        }else{
            int x;
            cin >> x;
            cout << a[x] << endl;
        }
    }
}