#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n , m , k , ans = INT_MAX , cnt;
char str[1001][1001];
int vis1[1001][1001] , vis2[1001][1001];
int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
pair<int,int> p[10000];
void dfs(int x , int y){
    if(vis1[x][y] >= vis2[x][y]) return;
    for(int i = 0 ; i < 4;i++){
        int xx = x + u[i][0];
        int yy = y + u[i][1];
        if(str[xx][yy] == '#' || vis1[xx][yy] != 0) continue;
        if(xx <= 0 || yy <= 0 || xx > n || yy > m){
            ans = min(ans , vis1[x][y]);
            continue;
        }
        if(str[xx][yy] == '.') {
            vis1[xx][yy] = vis1[x][y] + 1;
            dfs(xx , yy);
        }
    }
}
void dfs2(){
    queue<pair<int,int>> que;
    for(int i = 0 ; i < cnt ;i++){
        que.push(p[i]);
        vis2[p[i].first][p[i].second] = 0;
    }
    while(!que.empty()){
        pair<int,int> f = que.front();
        que.pop();
        for(int i = 0 ; i < 4;i++){
            int x = f.first + u[i][0];
            int y = f.second + u[i][1];
            if(x <= 0 || y <= 0 || x > n || y > m) continue;
            if(vis2[x][y] != -1) continue;
            vis2[x][y] = vis2[f.first][f.second] + 1;
            que.push({x , y});
        }
    }
}
int main(){
    cnt = 0;
    int a , b;
    cin >> n >> m;
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1 ; j <= m ;j++){
            vis1[i][j] = 0;
            vis2[i][j] = -1;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> str[i][j];
            if(str[i][j] == 'J'){
                a = i;
                b = j;
            }else if(str[i][j] == 'F'){
                p[cnt++] = {i,j};
            }
        }
    }
    dfs2();
    dfs(a , b);
    cout << ans + 1 << endl;
}