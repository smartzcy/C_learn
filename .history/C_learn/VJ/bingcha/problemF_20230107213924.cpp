#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n , m , f[100000];
struct qiao{
    int u , v;
    double w;
    qiao(int u , int v , double w) : u(u), v(v), w(w){}
    bool operator<(const qiao& other) const{
        return other.w > w;
    }
};
double getdi(int x1 , int y1 , int x2 , int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void INIT(){
    for(int i = 1; i <= n;i++) f[i] = i;
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
vector<pair<int , int> > vec;
vector<qiao> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    INIT();
    for(int i = 1 ; i <= n ;i++){
        int x , y;
        cin >> x >> y;
        vec.push_back({x , y});
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            qiao qq = qiao(i , j , getdi(vec[i].first , vec[i].second , vec[j].first , vec[j].second));
            cout << qq.w << " " << i << " " << j << endl;
            q.push_back(qq);
        }
    }
    cout << endl;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int x , y;
        cin >> x >> y;
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            f[fy] = fx;
        }
    }
    sort(q.begin() , q.end());
    for(auto i : q){
        cout << i.w << endl;
    }
    for(auto i : q){
        int fx = find(i.u);
        int fy = find(i.v);
        if(fx != fy){
            cout << i.u << " " << i.v << endl;
            f[fy] = fx;
        }
    }
}