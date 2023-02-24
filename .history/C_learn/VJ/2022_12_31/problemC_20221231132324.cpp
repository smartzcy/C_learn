#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long n , ans = 0;
        cin >> n;
        int k = (n + 1) / 2;
        for(int i = 0 ; i < k;i++){
            int num = 4 * (n - 2 * i - 1);
            ans += num * (k - i);
        }
        cout << ans << endl;
    }
}