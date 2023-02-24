#include <iostream>
#include <map>
using namespace std;
int main(){
    long long n , sum = 0 , ans = 0 , m = 0;
    cin >> n;
    map<long long , long long> map1;
    for(long long i = 0 ; i < n ; i++){
        long long num;
        cin >> num;
        sum += num;
        if(map1.find(sum) != map1.end() || sum == 0){
            if(m <= map1[sum] + 1){
                m = i;
                ans++;
            }
        }
        map1[sum] = i;
    }
    cout << ans << endl;
    return 0;
}