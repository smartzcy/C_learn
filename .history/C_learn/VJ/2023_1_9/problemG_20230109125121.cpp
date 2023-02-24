#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n , vis[101] , ans[101];
vector<int>vec[101];
queue<int> que;
void dfs(){
    int k = 1;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i] == 0) que.push(i);
    }
    while(!que.empty()){
        int t = que.front();
        que.pop();
        cout << t << " ";
        for(int i = 0 ; i < vec[t].size();i++){
            vis[vec[t][i]]--;
            if(vis[vec[t][i]] == 0) que.push(vec[t][i]);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1 , num; i <= n ; i++){
        while(cin >> num , num != 0){
            vec[i].push_back(num);
            vis[num]++;
        }
    }
    dfs();
}