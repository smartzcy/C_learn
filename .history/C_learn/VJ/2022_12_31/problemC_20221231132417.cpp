#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long n , ans = 0;
        cin >> n;
        int k = (n + 1) / 2 - 1;
        for(int i = k ; i >= k;i--){
            ans += (n * 4 - 4) * i;
            n -= 2;
        }
        cout << ans << endl;
    }
}