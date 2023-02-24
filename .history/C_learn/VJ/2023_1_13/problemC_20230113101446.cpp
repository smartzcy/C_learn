#include <iostream>
using namespace std;
const int N = 1e6;
long long a[N] , t1[N] , t2[N];
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
    long long sum = 0;
    while(x > 0){
        sum += a[x];
        x -= lowbit(x);
    }
    return sum;
}
int main(){
    cin >> n >> q;
    int pre = 0;
    for(int i = 1 ; i <= n ;i++){
        int num;
        cin >> num;
        a[i] = num - pre;
        pre = num;
    }
    for(int i = 1 ; i <= n ;i++){
        add(i , a[i]);
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
            cout << (r + 1) * getsum(r) - getsum(l - 1) << endl;
        }
    }
}