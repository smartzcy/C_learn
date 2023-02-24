#include<stdio.h>
#include<stdlib.h>
int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int num[1000];
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n;i++){
            scanf("%d",&num[i]);
        }
        qsort(num,n,sizeof(num[0]),cmp);
        int min = num[n/2];
        int direction = 0;
        for(int i = 0 ; i < n;i++){
            direction += (abs(min - num[i]));
        }
        printf("%d %d\n",min,direction);
    }
    return 0;
}