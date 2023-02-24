// #include <iostream>
// #include <array>
// #include <algorithm>
// using namespace std;
// int n, m, f[200000];
// int getf(int x)
// {
//     return x == f[x] ? x : f[x] = getf(f[x]);
// }
// void merge(int x, int y)
// {
//     int fx = getf(x);
//     int fy = getf(y);
//     f[fx] = fy;
// }
// array<int, 3> edge[10010];
// int ans, num;
// void kru()
// {
//     sort(edge + 1, edge + 1 + n);
//     for (int i = 1; i <= m; ++i)
//         f[i] = i;
//     ans = num = 0;
//     for (int i = 1; i <= n; ++i)
//     {
//         // auto [w, u, v] = edge[i];
//         int w = edge[i][0];
//         int u = edge[i][1];
//         int v = edge[i][2];
//         int fu = getf(u);
//         int fv = getf(v);
//         if (fu != fv)
//         {
//             num++;
//             ans += w;
//             f[fu] = fv;
//         }
//     }
// }
// int main()
// {
//     while (cin >> n >> m, n != 0)
//     {
//         for (int i = 1, u, v, w; i <= n; i++)
//         {
//             cin >> u >> v >> w;
//             edge[i] = {w, u, v};
//         }
//         kru();
//         int cnt = 0;
//         if (num != n - 1)
//             cout << "?" << endl;
//         else
//             cout << ans << endl;
//     }
// }

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxv = 110;
const int INF = 1000000000;
int n, m, mp[maxv][maxv];
int d[maxv];
bool vis[maxv] = {false};
int prim()
{
    fill(d, d + maxv, INF);
    d[1] = 0;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= m; j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return -1;
        vis[u] = true;
        ans += d[u];
        for (int v = 1; v <= m; v++)
        {
            if (vis[v] == false && mp[u][v] != INF && mp[u][v] < d[v])
            {
                d[v] = mp[u][v];
            }
        }
    }
    return ans;
}
int main()
{
    int x, y, w;
    while (scanf("%d%d", &n, &m), n != 0)
    {
        fill(mp[0], mp[0] + maxv * maxv, INF);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &w);
            mp[x][y] = mp[y][x] = w;
        }
        int res = prim();
        if (res != -1)
            printf("%d\n", res);
        else
            printf("?\n");

        fill(vis, vis + maxv, false);
    }
    return 0;
}