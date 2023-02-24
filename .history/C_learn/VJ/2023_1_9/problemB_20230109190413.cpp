#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a , b , c , flag;
int X , Y , Z , x2 , y2 , z2 , min1;
int vis[40][40][40] , viss[40][40][40];
int u[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
string str[40][40];
struct node{
    int x , y , z;
};
void dfs(int x , int y , int z , int step){
    queue<node> que;
    node aa;
    aa.x = x; aa.y = y; aa.z = z;
    que.push(aa);
    while(!que.empty()) {
        node bb = que.front();
        que.pop();
        for(int i = 0 ; i < 6;i++){
            int xx = bb.x + u[i][0];
            int yy = bb.y + u[i][1];
            int zz = bb.z + u[i][2];
            if(xx >= 0 && xx < a && yy >= 0 && yy < b && zz >= 0 && zz < c && vis[xx][yy][zz] == 0 && str[xx][yy][zz] == '.'){
                if(xx == x2 && yy == y2 && zz == z2) flag = 0;
                vis[xx][yy][zz] = vis[bb.x][bb.y][bb.z] + 1;
                node aa;
                aa.x = xx;
                aa.y = yy;
                aa.z = zz;
                que.push(aa);
            }
        }
    }
    // if(step >= min1 || viss[x][y][z] <= step) return;
    // viss[x][y][z] = step;
    // for(int i = 0 ; i < 6;i++){
    //     int xx = x + u[i][0];
    //     int yy = y + u[i][1];
    //     int zz = z + u[i][2];
    //     if(xx >= 0 && xx < a && yy >= 0 && yy < b && zz >= 0 && zz < c && vis[xx][yy][zz] == 0 && str[xx][yy][zz] == '.'){
    //         vis[xx][yy][zz] = 1;
    //         if(xx == x2 && yy == y2 && zz == z2){
    //             min1 = min(min1 , step + 1);
    //             flag = 0;
    //         }else{
    //             dfs(xx , yy , zz , step + 1);
    //         }
    //         vis[xx][yy][zz] = 0;
    //     }
    // }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> a >> b >> c , a != 0 && b != 0 && c != 0){
        min1 = 0x3f3f3f;
        flag = 1;
        for(int i = 0 ; i < a ; i++){
            for(int j = 0 ; j < b ;j++){
                cin >> str[i][j];
                for(int k = 0 ; k < c ; k++){
                    viss[i][j][k] = 0x3f3f3f3f;
                    vis[i][j][k] = 0;
                    if(str[i][j][k] == 'S'){
                        X = i;
                        Y = j;
                        Z = k;
                    }else if(str[i][j][k] == 'E'){
                        x2 = i;
                        y2 = j;
                        z2 = k;
                        str[i][j][k] = '.';
                    }
                }
            }
        }
        dfs(X , Y , Z , 0);
        if(flag == 0) cout << "Escaped in " << vis[x2][y2][z2] << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }
}