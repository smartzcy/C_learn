#include <iostream>
using namespace std;
const int N = 1e6;
long long t1[N] , t2[N];
int n , q;
logn long lowbit(logn long x){
    return x & -x;
}
void add(int x , long long val){
    long long val1 = val;
    long long val2 = val * x;
    while(x <= n){
        t1[x] += val1;
        t2[x] += val2;
        x += lowbit(x);
    }
}
long long getsum(int x){
    long long sum1 = 0;
    long long sum2 = 0;
    int xx = x;
    while(x > 0){
        sum1 += t1[x];
        sum2 += t2[x];
        x -= lowbit(x);
    }
    return sum1 * (xx + 1) - sum2;
}
int main(){
    cin >> n >> q;
    long long pre = 0;
    for(int i = 1 ; i <= n ;i++){
        long long num;
        cin >> num;
        add(i , num - pre);
        pre = num;
    }
    while(q--){
        int k , l , r;
        cin >> k >> l >> r;
        if(k == 1){
            int val;
            cin >> val;
            add(l , val);
            add(r + 1 , -val);
        }else{
            cout << getsum(r) - getsum(l - 1) << endl;
        }
    }
}