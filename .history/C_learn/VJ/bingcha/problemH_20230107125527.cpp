// #include <iostream>
// using namespace std;
// int n , k , f[100000] , di[100000];
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
//     int cnt = 0;
//     cin >> n >> k;
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

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5e4 + 10;
int p[N];
int d[N];
int n, k;
int res = 0;
void init()
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
}
int find(int x) // 路径压缩
{
    if (x != p[x])
    {
        int t = find(p[x]); // 保存好p[x],以免直接将p[x]变为根节点
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}
int main()
{
    scanf("%d%d", &n, &k);
    init();
    while (k--)
    {
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        if (a > n || b > n)
            res++;
        else
        {
            int fa = find(a), fb = find(b);
            if (x == 1)
            {
                if (fa == fb && (d[a] - d[b]) % 3 != 0)
                    res++;         // 判断在同一集合时，判断其关系是否满足
                else if (fa != fb) // 不在同一集合时，直接加入即可，处理好距离
                {
                    p[fa] = fb;
                    d[fa] = d[b] - d[a];
                }
            }
            else
            {
                if (fa == fb && (d[a] - d[b] - 1) % 3 != 0)
                    res++;
                else if (fa != fb)
                {
                    p[fa] = fb;
                    d[fa] = d[b] - d[a] + 1;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
