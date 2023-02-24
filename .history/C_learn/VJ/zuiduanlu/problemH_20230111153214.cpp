#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1e9;
int n , m , q;
int d[301][301];
int ma[301];
void floy(int x){
    for(int i = 0 ; i < n ;i++){
        if(i == x) continue;
        for(int j = 0 ; j < n; j++){
            if(i == j || j == x) continue;
            d[i][j] = min(d[i][j] , d[i][x] + d[x][j]);
        }
    }
}
int main(){
    while(cin >> n >> m >> q , n + m + q != 0){
        for(int i = 0 ; i < n ;i++){
            d[i][i] = 0; ma[i] = 0;
            for(int j = i + 1 ; j <= n ; j++){
                d[i][j] = inf;
                d[j][i] = inf;
            }
        }
        for(int i = 0 ; i < n ; i++){
            int u , v , w;
            cin >> u >> v >> w;
            d[u][v] = min(d[u][v] , w);
        }
        while(m--){
            int k;
            cin >> k;
            if(k == 0){
                int a;
                cin >> a;
                if(ma[a] == 0) {
                    ma[a] = 1;
                    floy(a);
                }else cout << "ERROR! At point " << a << endl;
            }else{
                int a , b;
                cin >> a >> b;
                if(ma[a] == 0 || ma[b] == 0) cout << "ERROR! At path " << a << " to " << b << endl;
                else{
                    if(d[a][b] != inf) cout << d[a][b] << endl;
                    else cout << "No such path" << endl;
                }
            }
        }
    }
}