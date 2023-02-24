#include<stdio.h>
int isSeven(int n){
    if(n % 7 == 0) return 0;
    while (n > 0)
    {
        if(n % 10 == 7) return 0;
        n /= 10;
    }
    return 1;
}
int main(){
    int N;
    scanf("%d",&N);
    while (N--)
    {
        int n;
        scanf("%d",&n);
        if(isSeven(n))printf("%d\n",n);
        else printf("pa\n");
    }
    return 0;
}