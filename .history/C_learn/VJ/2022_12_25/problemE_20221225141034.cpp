#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , k , a[300000];
        map<int, int> map1;
        cin >> n >> k;
        for(int i = 0 ; i < k ; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < k ; i++){
            int num;
            cin >> num;
            map1[a[i]] = num;
        }
        int k = 0;
        for(int i = 1 ; i <= n ;i++){
            int num = INT_MAX;
            for(auto j : map1){
                num = min(num , j.second + abs(j.first - i));
            }
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}