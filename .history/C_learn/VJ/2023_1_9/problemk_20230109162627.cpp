#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> vec[200001];
int ans = 0;
void dfs(int x){
    queue<int> que;
    que.push(x);
    ans++;
    while(!que.empty()){
        int a = que.front();
        que.pop();
        for(int i = 0 ; i < vec[a].size();i++){
            que.push(vec[a][i]);
        }
    }
}
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m;i++){
        int x , y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

}