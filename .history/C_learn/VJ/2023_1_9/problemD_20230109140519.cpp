#include<iostream>
using namespace std;
int n , m , k , ans , vis[1001][1001];
string str[1001];
int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void bfs(int x , int y){
    vis[x][y] = 1;
    for(int i = 0 ; i < 4;i++){
        int xx = x + u[i][0];
        int yy = y + u[i][1];
        // cout << xx << " " << yy << endl;
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0){
            // cout << xx << " " << yy << endl;
            if(str[xx][yy] == '*'){
                // cout << xx << " " << yy << endl;
                ans++;
            }
            if(str[xx][yy] == '.'){
                bfs(xx, yy);
            }
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> str[i];
    }
    for(int i = 0 ; i < k ; i++){
        ans = 0;
        for(int j = 0 ; j < n ;j++)
            for(int k = 0 ; k < m ;k++)
                vis[j][k] = 0;
        int x , y;
        cin >> x >> y;
        bfs(x - 1 , y - 1);
        cout << ans << endl;
    }
}