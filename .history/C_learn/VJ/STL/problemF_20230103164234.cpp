#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        unordered_map<int , int> map1 , map2;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            map1[num]++;
        }
        int sum = 0;
        for(auto i : map1) {
            sum += i.second;
            map2[i.second]++;
        }
        int ans = INT_MAX , k = map1.size() , num = 0;;
        for(auto i : map2){
            ans = min(ans , num + min(sum - k * i.first , i.second * i.first + sum - (k - i.second) * (map2.upper_bound(i.first)->first)));
            k -= i.second;
            sum -= i.second * i.first;
            num += i.second * i.first;
        }
        cout << ans << endl;
    }
}