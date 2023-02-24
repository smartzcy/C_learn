#include<stdio.h>
int main(){
    int num[16];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d",&num[i * 4 + j]);
        }
    }
    int min = num[0];
    int n = 0;
    for(int i = 1;i < 16;i++){
        if(min > num[i]){
            min = num[i];
            n = i;
        }
    }
    printf("%d %d",n / 4,n % 4);
}