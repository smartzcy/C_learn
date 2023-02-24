#include<stdio.h>
int main(){
    int num[3][3];
    while(scanf("%d" "%d" "%d",&num[0][0],&num[0][1],&num[0][2])!=EOF){
        for(int i=1; i<3; i++){
            for(int j=0; j<3; j++){
                scanf("%d",&num[i][j]);
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(j == 2){
                    printf("%d\n",num[j][i]);
                }else{
                    printf("%d ",num[j][i]);
                }
            }
        }
        printf("\n");
    }
}