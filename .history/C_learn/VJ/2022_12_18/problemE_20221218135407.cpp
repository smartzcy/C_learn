#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    map<int,int>map1;
    int n , num[200000];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> num[i];
        map1[num[i]] = i;
    }
    long long ans = 0;
    int right = 0;
    for(int i = 0 ; i < n ; i++){
        if(right < i) ans = (ans * 2) % 998244353;
        right = max(right , map1[num[i]]);
    }
    cout << ans << endl;
}