#include<stdio.h>
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int num1[20][20];
    int num2[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&num1[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            scanf("%d",&num2[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int num = 0;
            int i1;
            for(i1 = 0;i1 < m;i1++){
                num = num + num1[i][i1] * num2[i1][j];
            }
            if(j != k - 1){
                printf("%d ",num);
            }else{
                printf("%d\n",num);
            }
        }
    }
}