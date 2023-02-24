#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    while (n--)
    {
        long long int a,b;
        scanf("%lld",&a);
        scanf("%lld",&b);
        printf("%lld\n",a+b);
    }
    
}