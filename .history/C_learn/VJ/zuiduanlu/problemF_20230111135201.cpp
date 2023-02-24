#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 1e9;
const int N = 503;
int n , m;
int x1 , y1 , x2 , y2;
char str[N][N];
int d[N][N];
int vis[N][N];
int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void dfs(){
    d[x1][y1] = 0;
    queue<pair<int,int> > que;
    que.push({x1 , y1});
    while(!que.empty()) {
        pair<int,int> p = que.front();
        que.pop();
        vis[p.first][p.second] = 1;
        for(int i = 0 ; i < 4;i++){
            int xx = p.first + u[i][0];
            int yy = p.second + u[i][1];
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if(vis[xx][yy]) continue;
            if(str[p.first][p.second] == str[xx][yy]) d[xx][yy] = min(d[xx][yy] , d[p.first][p.second]);
            else d[xx][yy] = min(d[xx][yy] , d[p.first][p.second] + 1);
            que.push({xx , yy});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m , n != 0 && m != 0){
        for(int i = 0 ; i < n ; i++) cin >> str[i];
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < m ; j++){
                d[i][j] = inf;
                vis[i][j] = 0;
            }
        dfs();
        cout << d[x2][y2] << endl;
    }
}