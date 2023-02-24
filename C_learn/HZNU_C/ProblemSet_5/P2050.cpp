#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, m, **a;
    scanf("%d%d", &n, &m);
    a = new int* [n];
    for(int i = 0 ; i < n;i++){
        a[i] = new int[m];
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf(" ");
    }
    return 0;
}