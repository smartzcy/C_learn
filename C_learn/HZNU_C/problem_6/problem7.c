#include<stdio.h>
int main(){
    int T;
    double num = 0;
    scanf("%d",&T);
    for(int i = T % 2;i <= T;i+=2){
        if(i != 0){
            num += 1 / (double)i;
        }
    }
    printf("%.2f",num);
}