#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n , q;
long long a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    int pre = 0;
    for(int i = 1 ; i <= n ; i++){
        int num;
        cin >> num;
        a[i] = num - pre;
        pre = num;
    }
    for(int i = 1 ; i <= q ; i++){
        int k;
        cin >> k;
        if(k == 1){
            int l , r , x;
            cin >> l >> r >> x;
            a[l] += x;
            a[r + 1] -= x;
        }else{
            int x;
            cin >> x;
            long long sum = 0;
            for(int i = 1 ; i <= x ; i++){
                sum += a[i];
            }
            cout << sum << endl;
        }
    }
}