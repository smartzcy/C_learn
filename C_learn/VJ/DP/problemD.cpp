#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 10000;
int n = 1 , ans = 0;
int pr = 0;
struct Node{
    int w , v , k;
    friend bool operator<(const Node& a , const Node& b){
        if(a.w == b.w) return a.v > b.v;
        else return a.w < b.w;
    }
}node[N];
int pre[N] , dp[N];
int main(){
    while(cin >> node[n].w >> node[n].v){
        node[n].k = n;
        pre[n] = 0;
        dp[n] = 1;
        n++;
    }
    n--;
    sort(node + 1 , node + 1 + n);
    for(int i = 1 ; i <= n;i++){
        for(int j = 1 ; j < i ; j++){
            if(node[i].w > node[j].w && node[i].v < node[j].v){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                    if(dp[i] > ans){
                        ans = dp[i];
                        pr = i;
                    }
                }
            }
        }
    }
    vector<int> vec;
    while(pr != 0){
        vec.push_back(node[pr].k);
        pr = pre[pr];
    }
    cout << vec.size() << endl;
    for(int i = vec.size() - 1 ; i >= 0 ;i--) cout << vec[i] << endl;
}