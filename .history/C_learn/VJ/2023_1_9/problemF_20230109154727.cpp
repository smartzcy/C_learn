// #include<iostream>
// #include<queue>
// #include<algorithm>
// using namespace std;
// int n , m , k , cnt;
// char str[1001][1001];
// int vis1[1001][1001] , vis2[1001][1001];
// int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
// pair<int,int> p[10000];
// int dfs(int x , int y){
//     queue<pair<int,int> > que;
//     que.push({x , y});
//     vis1[x][y] = 0;
//     while(!que.empty()) {
//         pair<int,int> p = que.front();
//         que.pop();
//         for(int i = 0 ; i < 4;i++){
//             int xx = p.first + u[i][0];
//             int yy = p.second + u[i][1];
//             if(xx <= 0 || yy <= 0 || xx > n || yy > m){
//                 return vis1[p.first][p.second] + 1;
//             }
//             if(str[xx][yy] == '.' && vis1[xx][yy] == -1 && vis1[p.first][p.second] + 1 < vis2[xx][yy]){
//                 vis1[xx][yy] = vis1[p.first][p.second] + 1;
//                 // cout << xx << " " << yy << " " << vis1[xx][yy] << endl;
//                 que.push({xx , yy});
//             }
//         }
//     }
//     return -1;
// }
// void dfs2(){
//     queue<pair<int,int>> que;
//     for(int i = 0 ; i < cnt ;i++){
//         que.push(p[i]);
//         vis2[p[i].first][p[i].second] = 0;
//     }
//     while(!que.empty()){
//         pair<int,int> f = que.front();
//         que.pop();
//         for(int i = 0 ; i < 4;i++){
//             int x = f.first + u[i][0];
//             int y = f.second + u[i][1];
//             if(x <= 0 || y <= 0 || x > n || y > m) continue;
//             if(vis2[x][y] != -1) continue;
//             if(str[x][y] == '.'){
//                 vis2[x][y] = vis2[f.first][f.second] + 1;
//                 que.push({x , y});
//             }
//         }
//     }
// }
// int main(){
//     cnt = 0;
//     int a , b;
//     cin >> n >> m;
//     for(int i = 1 ; i <= n ;i++){
//         for(int j = 1 ; j <= m ;j++){
//             vis1[i][j] = -1;
//             vis2[i][j] = -1;
//         }
//     }
//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 1 ; j <= m ; j++){
//             cin >> str[i][j];
//             if(str[i][j] == 'J'){
//                 a = i;
//                 b = j;
//             }else if(str[i][j] == 'F'){
//                 p[cnt++] = {i,j};
//             }
//         }
//     }
//     dfs2();
//     int ans = dfs(a , b);
//     if(ans == -1) cout << "IMPOSSIBLE" << endl;
//     else cout << ans << endl;
// }

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node{
    int x, y;
    int step;
};
int n, m;
pair<int,int> f[1003];
int cnt;
char a[1003][1003];
int via[1003][1003];
int fire[1003][1003];
node t, d;
void bfs(){
    int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<node> Q;
    for (int i = 0; i < cnt; i++){
        t.x = f[i].first;
        t.y = f[i].second;
        t.step = 0;
        via[t.x][t.y] = 1;
        Q.push(t);
    }
    while (!Q.empty()){
        t = Q.front();
        Q.pop();
        fire[t.x][t.y] = t.step;
        for (int i = 0; i < 4; i++){
            d.x = t.x + next[i][0];
            d.y = t.y + next[i][1];
            d.step = t.step + 1;
            if (d.x < 0 || d.y < 0 || d.x >= n || d.y >= m) continue;
            if (a[d.x][d.y] == '.' && via[d.x][d.y] == 0){
                via[d.x][d.y] = 1;
                Q.push(d);
            }
        }
    }
}

int bfsr(int x, int y){
    int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<node> Q;
    t.x = x;
    t.y = y;
    t.step = 0;
    via[x][y] = 1;
    Q.push(t);
    while (!Q.empty()){
        t = Q.front();
        Q.pop();
        if (t.x == 0 || t.x == n - 1 || t.y == 0 || t.y == m - 1){
            return t.step;
        }
        for (int i = 0; i < 4; i++){
            d.x = t.x + next[i][0];
            d.y = t.y + next[i][1];
            d.step = t.step + 1;
            if (d.x < 0 || d.y < 0 || d.x >= n || d.y >= m)
                continue;
            if (a[d.x][d.y] == '.' && via[d.x][d.y] == 0 && d.step < fire[d.x][d.y]){
                via[d.x][d.y] = 1;
                Q.push(d);
            }
        }
    }
    return -1;
}

int main(){
    int jx , jy;
        cnt = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (a[i][j] == 'J'){
                    jx = i;
                    jy = j;
                }
                if (a[i][j] == 'F'){
                    f[cnt++] = {i , j};
                }
            }
        }
        memset(via, 0, sizeof(via));
        memset(fire, 0x3f, sizeof(fire));
        bfs();
        memset(via, 0, sizeof(via));
        int ans = bfsr(jx, jy);
        if (ans == -1){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << ans + 1 << endl;
        }
    return 0;
}