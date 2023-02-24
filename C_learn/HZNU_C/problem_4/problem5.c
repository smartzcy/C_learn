#include<stdio.h>
int gcd(int x,int y){
    if(x < y){
        int k = y;
        y = x;
        x = k;
    }
    while(x % y != 0){
        int k = x % y;
        x = y;
        y = k;
    }
    return y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        printf("%d ",gcd(n,m));
    }
    return 0;
}