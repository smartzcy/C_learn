#include <iostream>
#include <vector>
using namespace std;
const int N = 4e4 + 10;
vector<pair<int,int> > adj[N];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m;
        cin >> n >> m;
        for(int i = 1 ; i < n ; i++){
            int u , v , w;
            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        
    }
}