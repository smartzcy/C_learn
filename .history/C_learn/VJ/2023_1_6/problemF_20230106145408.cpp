#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI = acos(-1.0);
const double eqs = 1e-4;
int R[10010] , n , f;
double V[10010];
bool check(double x){
    int cnt = 0;
    int t = lower_bound(V , V + n , x) - V;
    for(int i = t ; i < n ; i++){
        cnt += (int)(V[i] / x);
    }
    return cnt >= (f + 1);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> f;
        for(int i = 0 ; i < n ;i++) {
            cin >> R[i];
            V[i] = PI * R[i] * R[i];
        }
        if(n == 1) cout << V[0] / (f + 1) << endl;
        else{
            sort(V , V + n);
            // for(int i = 0 ; i < n ;i++) cout << V[i] << endl;
            double l = 0.0 , r = V[n - 1];
            while(fabs(l - r) > eqs){
                double mid = (l + r) / 2;
                if(check(mid)) l = mid;
                else r = mid;
            }
            cout << l << endl;
        }
    }
}