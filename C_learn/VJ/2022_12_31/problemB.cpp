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
        for(int i = 0 ; i < n;i++){
            sum += a[i];
        }
        int a1 = 0 , b1 = 0 , max1 = sum;
        for(int i = 0 ; i < k;i++){
            sum -= a[i];
            sum += b[n - i - 1];
            max1 = max(max1 , sum);
        }
        cout << max1 << endl;
    }
}