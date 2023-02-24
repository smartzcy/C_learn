#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 10000;
int n = 1 , ans = 0;
int pr = 0;
int w[N] , v[N];
int pre[N] , dp[N];
int main(){
    while(cin >> w[n] >> v[n]) n++;
    n--;
    for(int i = 1 ; i <= n;i++){
        for(int j = i + 1 ; j <= n ; j++){
            if(w[j] > w[i] && v[j] < v[i]){
                if(dp[j] <= dp[i] + 1){
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                    if(dp[j] > ans){
                        ans = dp[j];
                        pr = j;
                    }
                }
            }
        }
    }
    vector<int> vec;
    while(pre[pr] != 0){
        vec.push_back(pr);
        pr = pre[pr];
    }
    cout << vec.size() + 1 << endl;
    cout << pr << endl;
    for(auto i : vec){
        cout << i << endl;
    }
}