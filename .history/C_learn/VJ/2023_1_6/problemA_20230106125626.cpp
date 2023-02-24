#include<iostream>
#include<algorithm>
using namespace std;
int num[200000] , n , c , d;
bool check(int x){
    int ans = 0 , k = 0 , nm = n - 1;
    while(k < d){
        if(ans >= c) return true;
        if(k % x == 0) nm = n - 1;
        else nm--;
        ans += num[nm];
    }
    if(ans < c) return false;
    else return true;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> c >> d;
        for(int i = 0 ; i < n ; i++) cin >> num[i];
        sort(num , num + n);
        if(num[n - 1] >= c){
            cout << "Infinity" << endl;
            continue;
        }else if(num[n - 1] * d < c){
            cout << "Impossible" << endl;
            continue;
        }
        int l = 1 , r = d;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) l = mid + 1;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}