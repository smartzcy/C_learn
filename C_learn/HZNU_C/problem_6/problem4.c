#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    return (*(int *)a) - (*(int *)b);
}
int main(){
    int T;
    scanf("%d",&T);
    int money[1000];
    while (T--)
    {
        int n , k , m;
        scanf("%d %d %d",&n,&k,&m);
        for(int i = 0; i < m ; i++){
            scanf("%d",&money[i]);
        }
        qsort(money, m, sizeof(money[0]),cmp);
        int mon = 0;
        for(int i = 0; i < k;i++){
            mon = mon + money[i];
        }
        if(mon > n){
            printf("%d\n",mon - n);
        }else{printf("0\n");}
    }
}