#include<stdio.h>
int main(){
    int n;
    while (scanf("%d",&n),n != 0)
    {
        int num[30][30];
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                scanf("%d",&num[i][j]);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = n - 1; k >= j + 1;k--){
                    if(num[i][k - 1] > num[i][k]){
                        int m = num[i][k - 1];
                        num[i][k - 1] = num[i][k];
                        num[i][k] = m;
                    }
                }
            }
        }
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(j != n -1)printf("%d ",num[i][j]);
                else printf("%d\n",num[i][j]);
            }
        }
    }
    return 0;
}