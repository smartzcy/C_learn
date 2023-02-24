#include<stdio.h>
int main(){
    int num[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d",&num[i][j]);
        }
    }
    int sum = 50 + num[0][0] + num[0][4] + num[1][1] + num[2][2] + num[1][3] + num[3][1] + num[3][3] + num[4][0] + num[4][4];
    printf("%d\n", sum);
    if(sum > 100){
        printf("wo de tian!");
    }else{
        printf("make monkey!");
    }
}