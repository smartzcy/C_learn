#include <iostream>
#include <set>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , sum = 0;
        multiset<int> set1;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            int num;
            cin >> num;
            int k = 0;
            set1.insert(num);
            for(auto it = set1.upper_bound(num); it != set1.end() ;it++) k++;
            sum += k;
            cout << k << endl;
            set1.erase(set1.begin() , set1.end());
        }
        cout << sum << endl;
    }
}