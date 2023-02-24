#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
int n, m, f[200000];
int getf(int x)
{
    return x == f[x] ? x : f[x] = getf(f[x]);
}
void merge(int x, int y)
{
    int fx = getf(x);
    int fy = getf(y);
    f[fx] = fy;
}
array<int, 3> edge[10000];
int ans, num;
void kru()
{
    sort(edge + 1, edge + 1 + n);
    for (int i = 1; i <= m; ++i)
        f[i] = i;
    ans = num = 0;
    for (int i = 1; i <= n; ++i)
    {
        auto [w, u, v] = edge[i];
        int fu = getf(u);
        int fv = getf(v);
        if (fu != fv)
        {
            num++;
            ans += w;
            f[fu] = fv;
        }
    }
}
int main()
{
    while (cin >> n >> m, n != 0)
    {
        for (int i = 1, u, v, w; i <= n; i++)
        {
            cin >> u >> v >> w;
            edge[i] = {w, u, v};
        }
        kru();
        int cnt = 0;
        if (num != n - 1)
            cout << "?" << endl;
        else
            cout << ans << endl;
    }
}