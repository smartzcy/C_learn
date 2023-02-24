#include<iostream>
using namespace std;
int n , k;
bool vis[9];
string str[9];
int ans , now;
void dfs(int x , int y){
    if(y == 1){
        ans++;
        return;
    }
    for(int i = x ; i <= n ; i++){
        for(int j = 0; j <= n; j++){
            if(str[i][j] == '#' && vis[j] != 1){
                vis[j] = 1;
                dfs(i + 1 , y - 1);
                vis[j] = 0;
            }
        }
    }
}
int main(){
    while(cin >> n >> k , n != -1 && k != -1){
        for(int i = 1 ; i <= n ; i++){
            cin >> str[i];
        }
        dfs(1 , k);
        cout << ans << endl;
    }
}