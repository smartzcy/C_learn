#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vec[200001];
int ans = 0;
int vis[200001];
void dfs(int x){
    if(ans > 1000000) return;
    ans++;
    for(int i = 0 ; i < vec[x].size();i++){
        int j = vec[x][i];
        if(vis[j] != 1){
            vis[j] = 1;
            dfs(j);
            vis[j] = 0;
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
    vis[1] = 1;
    dfs(1);
    cout << min(ans , 1000000) << endl;
}