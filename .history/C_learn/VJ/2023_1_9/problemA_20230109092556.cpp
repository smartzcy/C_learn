#include<iostream>
using namespace std;
int n , k;
bool vis[9][2];
string str[9];
int ans , now;
void dfs(int x){
    for(int i = 1 ; i <= n ; i++){
        if(str[x][i] == '#' && vis[x][0] != 1 && vis[i][1] != 1){
            now++;
            vis[x][0] = 1;
            vis[i][1] = 1;
            if(now == k) {
                ans++;
                now--;
            }
            for(int j = x + 1 ; j <= n ; j++){
                if(str[j].find('#') == string::npos){
                    dfs(j);
                    break;
                }
            }
            vis[x][0] = 0;
            vis[i][1] = 0;
            now--;
        }
    }
}
int main(){
    while(cin >> n >> k , n != -1 && k != -1){
        for(int i = 1 ; i <= n ; i++){
            cin >> str[i];
        }
    }
    dfs(1);
    cout << ans << endl;
}