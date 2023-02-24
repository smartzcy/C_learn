#include<stdio.h>
int main(){
    int N;
    int num[1001] = {0};
    scanf("%d",&N);
    while (N--)
    {
        int n,m,k;
        scanf("%d-%d %d",&n,&m,&k);
        num[n] += k;
    }
    int max = 0;
    num[0] = 0;
    for(int i = 1; i <= 1000;i++){
        if(num[i] != 0 && num[max] < num[i]) max = i;
    }    
    printf("%d %d",max,num[max]);
}