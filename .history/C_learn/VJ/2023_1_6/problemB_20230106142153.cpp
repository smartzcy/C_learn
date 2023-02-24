#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long n , x[100010] , t[100010];
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++) cin >> x[i];
        for(int i = 1 ; i <= n ; i++) cin >> t[i];
        long long min1 = LLONG_MAX , max1 = LLONG_MIN;
        for(int i = 1 ; i <= n ; i++){
            min1 = min(min1 , x[i] - t[i]);
            max1 = max(max1 , x[i] + t[i]);
        }
        cout << (min1 + max1) * 1.0 / 2 << endl;
    }
    return 0;
}