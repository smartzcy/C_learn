#include<stdio.h>
int main(){
    int a,b;
    int num = 1;
    scanf("%d %d",&a,&b);
    for(int i = 2; i<= a + b;i++){
        num *= i;
    }
    printf("%d",num);
    return 0;
}