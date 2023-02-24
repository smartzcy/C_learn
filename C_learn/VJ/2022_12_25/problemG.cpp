#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        unordered_set<int> set1;
        vector<int> vec;
        int n , ans = 0;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            int num;
            cin >> num;
            vec.push_back(num);
            set1.insert(num);
        }
        while(set1.size() != 1){
            set1.clear();
            for(int i = 0 ; i < n;i++){
                vec.push_back(__gcd(vec[i] , vec[(i + 1) % n]));
                set1.insert(vec[n + i]);
            }
            vec.erase(vec.begin(), vec.begin() + n);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}