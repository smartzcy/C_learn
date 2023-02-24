#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        unordered_map<int , int> map1;
        multiset<int> s;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            map1[num]++;
        }
        int sum = 0;
        for(auto i : map1) {
            sum += i.second;
            s.insert(i.second);
        }
        int ans = INT_MAX , k = s.size();
        for(multiset<int>::iterator i = s.begin(); i != s.end(); i++) {
            ans = min(ans , min(sum - k * (*i) , sum - (--k) * (*(i++))));
        }
        cout << ans << endl;
    }
}