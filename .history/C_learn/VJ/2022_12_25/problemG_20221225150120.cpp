#include <iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        unordered_set<int> set1;
        int n , num[200000] , ans = 0;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            cin >> num[i];
            set1.insert(num[i]);
        }
        while(set1.size() != 1){
            set1.clear();
            int sum = num[0];
            for(int i = 0 ; i < n - 1;i++){
                num[i] = __gcd(num[i] , num[i + 1]);
                set1.insert(num[i]);
            }
            num[n - 1] = __gcd(sum , num[n - 1]);
            set1.insert(num[n -1]);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}