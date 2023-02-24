#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin >> n , n != 0){
        pair<int , int> num[100];
        for(int i = 0 ; i < n ; i++){
            cin >> num[i].first >> num[i].second;
        }
        sort(num , num + n);
        int last = num[0].second , ans = 1;
        for(int i = 1 ; i < n ;i++){
            if(num[i].first > last){
                last = num[i].second;
                ans++;
            }
        }
        cout << ans << endl;
    }
}