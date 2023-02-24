#include<stdio.h>
int com(int x, int y) {
   return (x == y || 0 == y) ? 1 : com(x - 1, y) + com(x - 1, y - 1);
}
int main()
{
    int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",com(a,b));
    }
    return 0;
}