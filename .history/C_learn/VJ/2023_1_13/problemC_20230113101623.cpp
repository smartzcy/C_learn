#include <iostream>
using namespace std;
const int N = 1e6;
long long t1[N] , t2[N];
int n , q;
int lowbit(int x){
    return x & -x;
}
void add(int x , int val){
    int val1 = val;
    int val2 = val * x;
    while(x <= n){
        t1[x] += val1;
        t2[x] += val2;
        x += lowbit(x);
    }
}
long long getsum(int x){
    long long sum1 = 0;
    long long sum2 = 0;
    while(x > 0){
        sum1 += t1[x];
        sum2 += t2[x];
        x -= lowbit(x);
    }
    return sum1 * (x + 1) - sum2;
}
int main(){
    cin >> n >> q;
    int pre = 0;
    for(int i = 1 ; i <= n ;i++){
        int num;
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
            add(r , -val);
        }else{
            cout << getsum(r) - getsum(l - 1) << endl;
        }
    }
}