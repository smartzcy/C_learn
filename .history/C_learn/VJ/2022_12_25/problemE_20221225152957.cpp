#include<iostream>
using namespace std;
long long n , k , a[300000] , b[300001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1 ; i <= n ;i++) b[i] = INT_MAX;
        for(int i = 0 ; i < k ; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < k ; i++){
            int num;
            cin >> num;
            b[a[i]] = num;
        }
        for(int i = 2 ; i <= n ;i++){
            b[i] = min(b[i] , b[i - 1] + 1);
        }
        for(int i = n - 1 ; i >= 1 ;i--){
            b[i] = min(b[i] , b[i + 1] + 1);
        }
        for(int i = 1 ; i <= n;i++){
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
