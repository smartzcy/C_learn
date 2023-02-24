#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        int num;
        int remember = 0;
        scanf("%d", &num);
        while (num != 0)
        {
            int s;
            s = num % 10;
            remember  = remember * 10 + s;
            num /= 10;
        }
        printf("%d\n", remember);
    }
    return 0;
}