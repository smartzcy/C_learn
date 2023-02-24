#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n ,ans = 0 , vis[101];
vector<int>vec[101];
set<int>s;
void dfs(int x){
    vis[x] = 1;
    cout << x << " ";
    for(auto i : vec[x]){
        if(vis[i] == 0){
            dfs(i);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1 , num; i <= n ; i++){
        while(cin >> num , num != 0){
            vec[i].push_back(num);
            s.insert(num);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(s.find(i) == s.end()){
            dfs(i);
            break;
        }
    }
}