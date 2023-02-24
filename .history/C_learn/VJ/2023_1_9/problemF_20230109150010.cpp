#include<iostream>
#include<algorithm>
using namespace std;
int n , m , k , ans = INT_MAX;
char str[1001][1001];
int vis1[1001][1001] , vis2[1001][1001];
int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x , int y){
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
int main(){
    int a , b;
    int x , y;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> str[i][j];
            if(str[i][j] == 'J'){
                a = i;
                b = j;
            }else if(str[i][j] == 'F'){
                x = i;
                y = j;
            }
            vis1[i][j] = 0;
            vis2[i][j] = 0;
        }
    }
    dfs(a , b);
    cout << ans << endl;
}