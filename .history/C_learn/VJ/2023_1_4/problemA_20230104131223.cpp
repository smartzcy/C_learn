#include<iostream>
#include<set>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , sum = 0 , ans = 0;
        cin >> n;
        multiset<int> s;
        for(int i = 0 ; i < n;i++){
            int num;
            cin >> num;
            sum += num;
            s.insert(sum + 7777);
            if(sum == 7777) ans++;
            if(s.find(sum) != s.end()) ans++;
        }
        cout << ans << endl;
    }
}