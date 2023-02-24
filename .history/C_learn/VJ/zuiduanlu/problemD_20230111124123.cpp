#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int N = 1010;
const double inf = 1e9;
pair<int,int> p[N];
double d[N];
int vis[N];
vector<pair<int , double> > adj[N];
int n , Sx , Sy , Tx , Ty , V1 , V2;
double f(int x1 , int y1 , int x2 , int y2){
    return sqrt((x2 - x1) * (x2 - x1) * 1.0 + (y2 - y1) * (y2 - y1) * 1.0);
}
void dij(){
    for(int i = 0 ; i <= n + 1;i++){
        d[i] = inf;
    }
    d[0] = 0.0;
    for(int i = 0 ; i <= n + 1; i++){
        int u = 0;
        for(int j = 0  ; j <= n + 1;j++){
            if(!vis[j] && (u == 0 || d[j] < d[u])) u = j;
        }
        vis[u] = 1;
        for(auto [v , w] : adj[u]){
            d[v] = min(d[v] , d[u] + w);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int a , b;
        cin >> a >> b;
        p[i] = {a , b};
    }
    cin >> Sx >> Sy >> Tx >> Ty;
    cin >> V1 >> V2;
    adj[0].push_back({n + 1 , f(Sx, Sy, Tx, Ty) / (V1 * 1.0)});
    for(int i = 1 ; i <= n ; i++)
        adj[0].push_back({i , f(Sx , Sy , p[i].first , p[i].second) / (V1 * 1.0)});
    for(int i = 1 ; i <= n ;i++){
        double k = (p[i].first , p[i].second , Tx , Ty);
        double time = 0;
        if(k / (V2 * 1.0) <= 3) time = double(k / (V2 * 1.0));
        else time = 3.0 + (k - V2 * 3.0) / (V1 * 1.0);
        adj[i].push_back({n + 1 , time});
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j) continue;
            double k = (p[i].second , p[i].second , p[j].first , p[j].second);
            double time;
            if(k / (V2 * 1.0) <= 3) time = k / (V2 * 1.0);
            else time = 3.0 + (k - V2 * 3.0) / (V1 * 1.0);
            adj[i].push_back({j , time});
            adj[j].push_back({i , time});
        }
    }
    dij();
    cout << d[n + 1] << endl;
}