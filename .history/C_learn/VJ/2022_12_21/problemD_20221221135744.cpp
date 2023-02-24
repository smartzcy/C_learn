#include <iostream>
#include <map>
using namespace std;
int main(){
    int n , sum = 0 , ans = 0 , m = 0;
    cin >> n;
    map<int , int> map1;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        sum += num;
        if(map1.find(sum) != map1.end() || sum == 0){
            if(m <= map1[sum]){
                cout << m << " " << map1[sum] << endl;
                m = i;
                ans++;
            }
        }
        map1[sum] = i;
    }
    cout << ans << endl;
    return 0;
}