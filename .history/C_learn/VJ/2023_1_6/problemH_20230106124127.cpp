#include <iostream>
#include <cmath>
using namespace std;
int a[20] , n;
double way(double x){
    double ans = 0;
    for(int i = 0 ; i <= n ; i++){
        ans = ans * x + a[i];
    }
    return ans;
}
int main(){
    double l , r , eqs = 1e-5;
    cin >> n >> l >> r;
    for(int i = 0 ; i <= n ; i++) cin >> a[i];
    while(fabs(l - r) >= eqs){
        double mid = (l + r) / 2;
        if(way(mid - eqs) < way(mid + eqs)) l = mid;
        else r = mid;
    }
    cout << r << endl;
}