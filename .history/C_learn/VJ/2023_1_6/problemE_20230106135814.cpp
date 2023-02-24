#include<iostream>
#include<algorithm>
using namespace std;
long long a[100010] , b[100010];
int main(){
    long long n , q , k;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    b[n + 1] = 1e18;
    while(q--){
        cin >> k;
        int l = 0 , r = n + 1;
        while(l < r - 1){
            long long mid = (l + r) / 2;
            if(b[mid] > k) r = mid;
            else l = mid;
        }
        cout << a[r - 1] +  k - b[r - 1] << endl;
    }

}