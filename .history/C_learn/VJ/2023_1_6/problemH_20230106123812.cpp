#include <iostream>
using namespace std;
int a[20] , n;
double way(double x){
    double ans = x;
    for(int i = 0 ; i < n ; i++){
        ans = ans * x + a[i];
    }
    return ans;
}
int main(){
    double l , r , eqs = 1e-5;
    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int cnt = 1000;
    while(cnt--){
        double mid1 = l + (l + r) / 3;
        double mid2 = r - (l + r) / 3;
        if(way(mid1) > way(mid2)) l = mid1;
        else r = mid2;
    }
    cout << l << endl;
}