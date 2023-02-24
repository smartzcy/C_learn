#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int R , C , maxH , a , b , ans;
int H[101][101];
int dp[101][101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ans = 0;
    cin >> R >> C;
    for(int i = 1 ; i <= R;i++){
        for(int j = 1 ; j <= C;j++){
            cin >> H[i][j];
            if(maxH < H[i][j]){
                a = i;
                b = j;
                maxH = H[i][j];
            }
        }
    }
    queue<pair<int,int> > que;
    que.push({a , b});
    dp[a][b] = 1;
    int u[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};
    while(!que.empty()){
        pair<int , int> p = que.front();
        que.pop();
        for(int i = 0 ; i < 4;i++){
            int xx = p.first + u[i][0];
            int yy = p.second + u[i][1];
            if(xx <= 0 || xx > R || yy <= 0 || yy > C) continue;
            if(H[xx][yy] > H[p.first][p.second]) continue;
            dp[xx][yy] = max(dp[xx][yy] , dp[p.first][p.second] + 1);
            ans = max(ans , dp[xx][yy]);
            que.push({xx , yy});
        }
    }
    cout << ans << endl;
}