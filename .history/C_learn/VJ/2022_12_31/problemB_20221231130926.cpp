#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , k , a[40] , b[40] , sum = 0;
        cin >> n >> k;
        for(int i = 0 ; i < n ; i++) cin >> a[i];
        for(int i = 0 ; i < n ; i++) cin >> b[i];
        sort(a , a + n);
        sort(b , b + n);
        for(int i = k ; i < n;i++){
            sum += a[i];
        }
        int a1 = 0 , b1 = 0;
        for(int i = 0 ; i < k;i++){
            a1 += a[i];
            b1 += b[n - i - 1];
        }
        cout << sum + max(a1 , b1) << endl;
    }
}