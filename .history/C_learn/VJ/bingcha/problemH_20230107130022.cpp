#include <iostream>
using namespace std;
int n , k , f[100000] , di[100000];
void INIT(){
    for(int i = 1 ; i<= n ; i++) f[i] = i;
}
int find(int x){
    if(x != f[x]){
        int t = find(f[x]);
        di[x] += di[f[x]];
        f[x] = t;
    }
    return f[x];
}
int main(){
    int cnt = 0;
    cin >> n >> k;
    while(k--){
        INIT();
        int d , x , y;
        cin >> d >> x >> y;
        if(x > n || y > n) cnt++;
        else{
            int fx = find(x);
            int fy = find(y);
            if(d == 1){
                if(fx == fy &&(di[x] - di[y]) % 3 != 0) {
                    cnt++;
                    cout << x << " " << y << endl;
                }
                else if(fx != fy){
                    f[fx] = fy;
                    di[fx] = di[y] - di[x];
                }
            }else{
                if(fx == fy &&(di[x] - di[y] - 1) % 3 != 0) {
                    cnt++;
                }
                else if(fx != fy){
                    f[fx] = fy;
                    di[fx] = di[y] - di[x] + 1;
                }
            }
        }
    }
    cout << cnt << endl;
}
