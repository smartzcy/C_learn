#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 10000;
int n = 1 , ans = 0;
int pr = 0;
struct Node{
    int w , v , k;
    bool operator<(const Node& a) const { return w > a.w ;}
}node[N];
int pre[N] , dp[N];
int main(){
    while(cin >> node[n].w >> node[n].v){
        node[n].k = n;
        n++;
    }
    n--;
    sort(node + 1 , node + 1 + n);
    for(int i = 1 ; i <= n;i++){
        for(int j = i + 1 ; j <= n ; j++){
            if(node[j].v < node[i].v){
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
        vec.push_back(node[pr].k);
        pr = pre[pr];
    }
    cout << vec.size() + 1 << endl;
    cout << node[pr].k << endl;
    for(int i = vec.size() - 1 ; i >= 0 ;i--) cout << vec[i] << endl;
}