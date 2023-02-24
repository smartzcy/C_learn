#include<iostream>
using namespace std;
int n , m , f[110];
void INIT(){
    for(int i = 1 ; i <= n ; i++) f[i] = i;
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main(){
    cin >> n >> m;
    INIT();
    while(m--){
        int x , y;
        cin >> x >> y;
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            f[fy] = fx;
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(f[i] == i) ans++;
    }
    cout << ans << endl;
}