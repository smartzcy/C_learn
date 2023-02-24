#include<stdio.h>
int isPrime(int x){
    if(x == 1) return 0;
    int j;
    for (j = 2; j < x; j++){
        if (x % j == 0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(isPrime(n))
        {
            printf("YES ");
        }
        else
        {
            printf("NO ");
        }
    }
    return 0;
}