#include<iostream>
#include<algorithm>
using namespace std;
long long num[200000] , n , c , d;
bool check(int x){
    long long sum = 0 , temp = 0;
    k++;
    for(int i = 0 ; i < k ; i++){
        if(i >= n) continue;
        else temp += num[i];
    }
    int nowd = d;
    while(nowd){
        if(nowd > k){
            sum += temp;
            nowd -= k;
        }else{
            for(int i = 0 ; i < nowd ; i++){
                if(i >= n) continue;
                sum += a[i];
            }
            nowd = 0;
        }
    }
    return sum < c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> c >> d;
        for(int i = 0 ; i < n ; i++) cin >> num[i];
        sort(num , num + n , greater<int>());
        if(num[0] >= c){
            cout << "Infinity" << endl;
            continue;
        }else if(num[0] * d < c){
            cout << "Impossible" << endl;
            continue;
        }else if(num[0] * d == c){
            cout << 0 << endl;
            continue;
        }
        int l = 0 , r = d + 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) l = mid + 1;
            else r = mid;
        }
        cout << l - 1 << endl;
    }
}