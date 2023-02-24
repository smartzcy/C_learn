#include <iostream>
#include<algorithm>
using namespace std;
int num[200000] , n , m;
bool check(int x){
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(num[i] >= x) ans += x;
        else ans += num[i] + (x - num[i]) / 2;
    }
    return ans >= m;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0 ; i < m ;i++){
            int x;
            cin >> x;
            num[x]++;
        }
        sort(num , num + n);
        int l = 1 , r = m;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << r + 1 << endl;
    }
}