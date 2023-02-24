#include <iostream>
using namespace std;
const int inf = 1e9;
int n , m , q;
int d[301][301];
struct node{
    int x , y , c;
    int k = 0;
}adj[301];
int main(){
    while(cin >> n >> m >> q , n + m + q != 0){
        for(int i = 0 ; i < n ; i++){
            cin >>  adj[i].x >> adj[i].y >> adj[i].c;
        }
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                d[i][j] = inf;
        while(m--){
            int k;
            cin >> k;
            if(k == 0){
                int a;
                cin >> a;
                if(adj[a].k == 0) adj[a].k = 1;
                else cout << "ERROR! At point " << a << endl;
            }else{
                int a , b;
                cin >> a >> b;
                if(adj[a].k == 0 || adj[b].k == 0) cout << "ERROR! At path " << a << " to " << b << endl;
                else{
                    
                }
            }
        }
    }
}