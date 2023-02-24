#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n , num[10001] , ans = 0;
    cin >> n;
    vector<int> vec[10001];
    for(int i = 0 ; i< n ;i++) {
        cin >> num[i];
        vec[num[i]].push_back(i);
    }
    int p = 0 , q = 0;
    for(int i = 0 ; i < n ; i++){
        if(p == q){
            if(p != num[i]){
                ans++;
                p = num[i];
            }
        }else if(p == num[i]){
            p = num[i];
        }else if(q == num[i]){
            q = num[i];
        }else{
            int pp = lower_bound(vec[p].begin(), vec[p].end(), i) - vec[p].begin();
            int qq = lower_bound(vec[q].begin(), vec[q].end(), i) - vec[q].begin();
            if(pp >= vec[p].size()) q = num[i];
            else if(qq >= vec[q].size()) p = num[i];
            else if(vec[p][pp] > vec[q][qq]) q = num[i];
            else p = num[i];
            ans++;
        }
    }
    cout << ans << endl;
}