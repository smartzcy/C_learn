// #include<iostream>
// #include<algorithm>
// using namespace std;
// int a , b , c , flag;
// int X , Y , Z , x2 , y2 , z2 , min1;
// int vis[40][40][40] , viss[40][40][40];
// int u[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
// string str[40][40];
// void dfs(int x , int y , int z , int step){
//     if(step >= min1 || viss[x][y][z] <= step) return;
//     viss[x][y][z] = step;
//     for(int i = 0 ; i < 6;i++){
//         int xx = x + u[i][0];
//         int yy = y + u[i][1];
//         int zz = z + u[i][2];
//         if(xx >= 0 && xx < a && yy >= 0 && yy < b && zz >= 0 && zz < c && vis[xx][yy][zz] == 0 && str[xx][yy][zz] == '.'){
//             vis[xx][yy][zz] = 1;
//             if(xx == x2 && yy == y2 && zz == z2){
//                 min1 = min(min1 , step + 1);
//                 flag = 0;
//             }else{
//                 dfs(xx , yy , zz , step + 1);
//             }
//             vis[xx][yy][zz] = 0;
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     while(cin >> a >> b >> c , a != 0 && b != 0 && c != 0){
//         min1 = 0x3f3f3f;
//         flag = 1;
//         for(int i = 0 ; i < a ; i++){
//             for(int j = 0 ; j < b ;j++){
//                 cin >> str[i][j];
//                 for(int k = 0 ; k < c ; k++){
//                     viss[i][j][k] = 0x3f3f3f3f;
//                     vis[i][j][k] = 0;
//                     if(str[i][j][k] == 'S'){
//                         X = i;
//                         Y = j;
//                         Z = k;
//                     }else if(str[i][j][k] == 'E'){
//                         x2 = i;
//                         y2 = j;
//                         z2 = k;
//                         str[i][j][k] = '.';
//                     }
//                 }
//             }
//         }
//         dfs(X , Y , Z , 0);
//         if(flag == 0) cout << "Escaped in " << min1 << " minute(s)." << endl;
//         else cout << "Trapped!" << endl;
//     }
// }

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
const int N = 35;
char mapp[N][N][N];
int vis[N][N][N];
int viss[N][N][N];
int l, n, m;
int Z, X, Y;
int u[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int minn = 20;
bool flag = true;
void dfs(int z, int x, int y, int step){
    if (step >= minn || viss[z][x][y] <= step) return;
    viss[z][x][y] = step;
    for (int i = 0; i < 6; i++){
        int zz = z + u[i][0];
        int xx = x + u[i][1];
        int yy = y + u[i][2];
        if (zz >= 0 && zz < l && xx >= 0 && xx < n && yy >= 0 && yy < m && (!vis[zz][xx][yy]) && (mapp[zz][xx][yy] == '.')){
            vis[zz][xx][yy] = 1;
            if (zz == Z && xx == X && yy == Y){
                flag = false;
                minn = min(step + 1, minn);
            }else dfs(zz, xx, yy, step + 1);
            vis[zz][xx][yy] = 0;
        }
    }
}
int main(){
    while (scanf("%d %d %d", &l, &n, &m) == 3, l + n + m){
        memset(vis, 0, sizeof(vis));
        memset(viss, 0x3f3f3f3f, sizeof(viss));
        minn = 40;
        flag = true;
        for (int k = 0; k < l; k++)
            for (int i = 0; i < n; i++)
                scanf("%s", mapp[k][i]);
        int a, b, c;
        for (int k = 0; k < l; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (mapp[k][i][j] == 'S'){
                        a = k;
                        b = i;
                        c = j;
                    }
                    if (mapp[k][i][j] == 'E'){
                        Z = k;
                        X = i;
                        Y = j;
                        mapp[k][i][j] = '.';
                    }
                }
            }
        }
        dfs(a, b, c, 0);
        if (!flag) printf("Escaped in %d minute(s).\n", minn);
        else printf("Trapped!\n");
    }
    return 0;
}