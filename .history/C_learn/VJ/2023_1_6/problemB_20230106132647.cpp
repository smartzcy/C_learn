#include<iostream>
#include<cmath>
using namespace std;
int n , x[100010] , t[100010];
bool check(double y){
    double ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans += fabs(x[i] - y);
    }
    return ans;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++) cin >> x[i];
        for(int i = 1 ; i <= n ; i++) cin >> t[i];
        double l = 1 , r = n , eqs = 1e-6;
        while(fabs(l - r) > eqs){
            double mid = (l + r) / 2;
            if(check(mid + eqs) > check(mid - eqs)) l = mid;
            else r = mid;
        }
        cout << l << endl;
    }
}