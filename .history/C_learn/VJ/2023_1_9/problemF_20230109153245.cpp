#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n , m , k , cnt;
char str[1001][1001];
int vis1[1001][1001] , vis2[1001][1001];
int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
pair<int,int> p[10000];
int dfs(int x , int y){
    queue<pair<int,int> > que;
    que.push({x , y});
    vis1[x][y] = 0;
    while(!que.empty()) {
        pair<int,int> p = que.front();
        que.pop();
        for(int i = 0 ; i < 4;i++){
            int xx = p.first + u[i][0];
            int yy = p.second + u[i][1];
            if(xx <= 0 || yy <= 0 || xx > n || yy > m){
                return vis1[x][y] + 1;
            }
            if(str[xx][yy] == '.' && vis1[xx][yy] == -1 && vis1[x][y] + 1 >= vis2[x][y]){
                vis1[xx][yy] = vis1[x][y] + 1;
                cout << xx << " " << yy << " " << vis1[xx][yy] << endl;
                que.push({xx , yy});
            }
        }
    }
    return -1;
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
            if(str[x][y] == '.'){
                vis2[x][y] = vis2[f.first][f.second] + 1;
                que.push({x , y});
            }
        }
    }
}
int main(){
    cnt = 0;
    int a , b;
    cin >> n >> m;
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1 ; j <= m ;j++){
            vis1[i][j] = -1;
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
    int ans = dfs(a , b);
    if(ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}