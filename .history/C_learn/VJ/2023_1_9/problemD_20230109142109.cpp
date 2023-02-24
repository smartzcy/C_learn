#include<iostream>
#include<unordered_map>
using namespace std;
int n , m , k , ans[100000] , vis[1001][1001] , temp = 0;
string str[1001];
int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void bfs(int x , int y){
    vis[x][y] = temp;
    for(int i = 0 ; i < 4;i++){
        int xx = x + u[i][0];
        int yy = y + u[i][1];
        // cout << xx << " " << yy << endl;
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0){
            cout << xx << " " << yy << endl;
            if(str[xx][yy] == '*'){
                // cout << xx << " " << yy << endl;
                ans[temp]++;
            }
            if(str[xx][yy] == '.'){
                bfs(xx, yy);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> str[i];
    }
    for(int i = 0 , x , y ; i < k ; i++){
        cin >> x >> y;
        temp++;
        if(!vis[x][y]){
            bfs(x , y);
        }
        cout << ans[vis[x][y]] << endl;
    }
}