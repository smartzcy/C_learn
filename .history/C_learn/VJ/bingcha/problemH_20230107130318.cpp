#include <iostream>
using namespace std;
int n , k , f[100000] , d[100000];
void INIT(){
    for(int i = 1 ; i<= n ; i++) f[i] = i;
}
int find(int x){
    if(x != f[x]){
        int t = find(f[x]);
        d[x] += d[f[x]];
        f[x] = t;
    }
    return f[x];
}
int main(){
    int cnt = 0;
    cin >> n >> k;
    while(k--){
        INIT();
        int k , x , y;
        cin >> k >> x >> y;
        if(x>n||y>n) cnt++;
        else {
            int fa=find(x),fb=find(y);
            if(k==1) {
                if(fa==fb&&(d[x]-d[y])%3!=0) cnt++;
                else if(fa!=fb){
                    f[fa]=fb;
                    d[fa]=d[y]-d[x];
                }
            }
            else{
                if(fa==fb&&(d[x]-d[y]-1)%3!=0) cnt++;
                else if(fa!=fb)
                {
                    f[fa]=fb;
                    d[fa]=d[y]-d[x]+1;
                }
            }
        }
    }
    cout << cnt << endl;
}
