#include<stdio.h>
int main(){
    int n,m;
    int t = 1;
    while (scanf("%d %d",&n,&m),n != 0)
    {
        if(t != 1) printf("\n");
        int max = 0;
        for(int i = 0;i < n*m;i++){
            int num;
            scanf("%d",&num);
            if(max < num) max = num;
        }
        printf("Case %d:\n",t++);
        printf("%d\n",max);
    }
    return 0;
}