#include<iostream>
using namespace std;
int n , f[100000] , d[100000];
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
void INIT(){
    for(int i = 1 ; i <= n ; i++){
        f[i] = i;
    }
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int cnt = 0;
        cin >> n;
        INIT();
        for(int i = 1 ; i <= n ; i++){
            int x , y;
            cin >> x >> y;
            int fx = find(x);
            int fy = find(y);
            if(fx == fy) d[fx]++;
            else {
                f[fy] = fx;
                d[fx] += d[fy] + 1;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            cnt = max(cnt , d[i]);
        }
        cout << cnt << endl;
    }
}