// #include <iostream>
// using namespace std;
// int n , k , f[100010] , di[100010];
// void INIT(){
//     for(int i = 1 ; i<= n ; i++) f[i] = i;
// }
// int find(int x){
//     if(x != f[x]){
//         int t = find(f[x]);
//         di[x] += di[f[x]];
//         f[x] = t;
//     }
//     return f[x];
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int cnt = 0;
//     cin >> n >> k;
//     INIT();
//     while(k--){
//         int d , x , y;
//         cin >> d >> x >> y;
//         if(x > n || y > n) cnt++;
//         else{
//             int fx = find(x);
//             int fy = find(y);
//             if(d == 1){
//                 if(fx == fy &&(di[x] - di[y]) % 3 != 0) cnt++;
//                 else if(fx != fy){
//                     f[fx] = fy;
//                     di[fx] = di[y] - di[x];
//                 }
//             }else{
//                 if(fx == fy &&(di[x] - di[y] - 1) % 3 != 0) cnt++;
//                 else if(fx != fy){
//                     f[fx] = fy;
//                     di[fx] = di[y] - di[x] + 1;
//                 }
//             }
//         }
//     }
//     cout << cnt << endl;
// }

#include <iostream>
#include <cstdio>
using namespace std;
int pre[50003], rel[50003];
int f(int x){
    if (x == pre[x])
        return x;
    int tmp = pre[x];
    pre[x] = f(pre[x]);
    rel[x] = (rel[x] + rel[tmp]) % 3;
    return pre[x];
}
int link(int x, int y, int flag){
    int root1 = f(x), root2 = f(y);
    if (root1 == root2){
        if (flag != (3 - rel[x] + rel[y]) % 3) return 0;
        else return 1;
    }
    pre[root2] = root1;
    rel[root2] = (rel[x] + flag + 3 - rel[y]) % 3;
    return 1;
}

int main(){
    int n, k, flag, x, y;
    scanf("%d %d", &n, &k);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        pre[i] = i;
        rel[i] = 0;
    }
    while (k--){
        scanf("%d%d%d", &flag, &x, &y);
        if (x > n || y > n){
            ans++;
            continue;
        }
        if (flag == 2 && x == y){
            ans++;
            continue;
        }
        if (!link(x, y, flag - 1))
            ans++;
    }
    printf("%d\n", ans);
}