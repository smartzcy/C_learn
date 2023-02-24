// #include<iostream>
// #include<cmath>
// #include<cstdio>
// #include<vector>
// using namespace std;
// const int N = 1050;
// const double inf = 1e15;
// pair<int,int> p[N];
// double d[N];
// int vis[N];
// vector<pair<int , double> > adj[N];
// int n , Sx , Sy , Tx , Ty , V1 , V2;
// double f(int x1 , int y1 , int x2 , int y2){
//     return sqrt((x2 - x1) * (x2 - x1) * 1.0 + (y2 - y1) * (y2 - y1) * 1.0);
// }
// void dij(){
//     for(int i = 0 ; i <= n + 1;i++){
//         d[i] = inf;
//         vis[i] = 0;
//     }
//     d[0] = 0.0;
//     for(int i = 0 ; i <= n + 1; i++){
//         int u = -1;
//         for(int j = 0  ; j <= n + 1;j++)
//             if(!vis[j] && (u == -1 || d[j] < d[u]))
//                 u = j;
//         vis[u] = 1;
//         for(auto [v , w] : adj[u])
//             d[v] = min(d[v] , d[u] + w);
//     }
// }
// int main(){
//     scanf("%d", &n);
//     for(int i = 1 ; i <= n ; i++){
//         int a , b;
//         scanf("%d %d" , &a , &b);
//         p[i] = {a , b};
//     }
//     scanf("%d %d %d %d" , &Sx , &Sy , &Tx , &Ty);
//     scanf("%d %d" , &V1 , &V2);
//     adj[0].push_back({n + 1 , f(Sx, Sy, Tx, Ty) / (V1 * 1.0)});
//     for(int i = 1 ; i <= n ; i++)
//         adj[0].push_back({i , f(Sx , Sy , p[i].first , p[i].second) / (V1 * 1.0)});
//     for(int i = 1 ; i <= n ;i++){
//         double k = sqrt((p[i].first - Tx) * (p[i].first - Tx) * 1.0 + (p[i].second - Ty) * (p[i].second - Ty) * 1.0);
//         double time = 0.0;
//         if(k / (V2 * 1.0) <= 3) time = double(k / (V2 * 1.0));
//         else time = double(3.0 + (k - V2 * 3.0) / (V1 * 1.0));
//         adj[i].push_back({n + 1 , time});
//     }
//     for(int i = 1 ; i <= n ; i++){
//         for(int j = i + 1 ; j <= n ; j++){
//             double k = sqrt((p[i].first - p[j].first) * (p[i].first - p[j].first) * 1.0 + (p[i].second - p[j].second) * (p[i].second - p[j].second) * 1.0);
//             double time = 0.0;
//             if(k / (V2 * 1.0) <= 3) time = double(k / (V2 * 1.0));
//             else time = double(3.0 + (k - V2 * 3.0) / (V1 * 1.0));
//             adj[i].push_back({j , time});
//             adj[j].push_back({i , time});
//         }
//     }
//     dij();
//     printf("%.12lf" , d[n + 1]);
// }

#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
const int N = 1100;
int n, qx, qy, zx, zy, v1, v2;
double dist[N];
bool st[N];
vector<pair<int, int> > v;
vector<pair<int, double> > adj[N];
double jl(int x1, int y1, int x2, int y2){
    return sqrt((x1 * 1.0 - x2) * (x1 - x2) + (y1 * 1.0 - y2) * (y1 - y2));
}
void solve(){
    for (int i = 0; i <= n + 1; i++) dist[i] = 1e18;
    dist[0] = 0;
    st[0] = true;
    queue<int> q;
    q.push(0);
    while (q.size()){
        int x = q.front();
        q.pop();
        st[x] = false;
        for (int i = 0; i < adj[x].size(); i++){
            int node = adj[x][i].first;
            double len = adj[x][i].second;
            if (dist[node] > dist[x] + len){
                dist[node] = dist[x] + len;
                if (!st[node])
                    q.push(node);
            }
        }
    }
    printf("%.12lf\n", dist[n + 1]);
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back({a, b});
    }
    scanf("%d%d%d%d%d%d", &qx, &qy, &zx, &zy, &v1, &v2);
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int x1 = v[i].first, y1 = v[i].second;
            int x2 = v[j].first, y2 = v[j].second;
            double k = jl(x1, y1, x2, y2), t;
            if (k > 3 * v2) t = (k - 3 * v2) / v1 + 3;
            else t = k / v2;
            adj[i + 1].push_back({j + 1, t});
            adj[j + 1].push_back({i + 1, t});
        }
    }
    for (int i = 0; i < n; i++){
        int x1 = v[i].first, y1 = v[i].second;
        double k = jl(x1, y1, qx, qy), t;
        t = k / v1;
        adj[0].push_back({i + 1, t});
    }
    adj[0].push_back({n + 1, jl(qx, qy, zx, zy) / v1 * 1.0});
    for (int i = 0; i < n; i++){
        int x1 = v[i].first, y1 = v[i].second;
        double k = jl(x1, y1, zx, zy), t;
        if (k > 3 * v2) t = (k - 3 * v2) / v1 + 3;
        else t = k / v2;
        adj[i + 1].push_back({n + 1, t});
    }
    solve();
    return 0;
}