#include<iostream>
#include<set>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long n , sum = 0 , ans = 0;
        cin >> n;
        multiset<long long> s;
        for(int i = 0 ; i < n;i++){
            long long num;
            cin >> num;
            sum += num;
            s.insert(sum + 7777);
            if(sum == 7777) ans++;
            if(s.find(sum) != s.end()) ans++;
        }
        cout << ans << endl;
    }
}