#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long a,b;
        scanf("%lld %lld",&b,&a);
        if((a&b)==b)printf("1\n");else printf("0\n");
    }
}