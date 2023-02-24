#include<stdio.h>
int f(int  n){
    int k = 1 , num = 1;
    int i = 1;
    while (i != n)
    {
        k = k + num;
        num = k - num;
        i++;
    }
    return num;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n;
        scanf("%d",&n);
        printf("%d\n ",f(n));
    }
    return 0;
}