#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        int num1[24], num2[24];
        for(int i = 0 ; i < 24 ; i++){
            num1[i] = 0;
            num2[i] = 0;
        }
        int num = 0;
        int n,m;
        scanf("%d %d",&n,&m);
        int a , b;
        for(int i = 0 ; i < n; i++){
            scanf("%d %d",&a,&b);
            for(int j = a - 1;j < b ; j++)
                num1[j] = 1;
        }
        for(int i = 0 ; i < m; i++){
            scanf("%d %d",&a,&b);
            for(int j = a - 1;j < b ; j++)
                num2[j] = 1;
        }
        for(int i = 0 ; i < 24 ; i++)
            if(num1[i] == 1 && num2[i] == 1)
                num++;
        printf("%d\n",num);
    }
}