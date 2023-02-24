#include <iostream>
#include <algorithm>
using namespace std;
char a[55][55];
int x, y, n, m;
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void calNext(int x, int y)
{
    if (y == m - 1)
    {
        x++;
        y = 0;
        return;
    }
    y++;
}
int main()
{
    scanf("%d%d", &n, &m);
    int vx[] = {0, 0, n - 1, n - 1};
    int vy[] = {m - 1, 0, m - 1, 0};
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    double ans = 0;
    for (int x1 = 0; x1 < n; x1++)
        for (int y1 = 0; y1 < m; y1++)
        {
            calNext(x1, y1);
            for (int x2 = x; x2 < n; x2++)
                for (int y2 = y; y2 < m; y2++)
                {
                    if (a[x1][y1] == a[x2][y2])
                    {
                        double a = dis(x1, y1, x2, y2);
                        for (int i = 0; i < 4; i++)
                        {
                            double b = dis(x1, y1, vx[i], vy[i]), c = dis(x2, y2, vx[i], vy[i]);
                            double p = (a + b + c) / 2;
                            double s = sqrt(p * (p - a) * (p - b) * (p - c)) * 2;
                            ans = max(ans, s);
                        }
                    }
                }
        }
    cout << ans << endl;
    return 0;
}
