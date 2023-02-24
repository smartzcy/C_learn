#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num1,num2;
    scanf("%d",&num1);
    for(int i = 1 ; i < n;i++){
        scanf("%d",&num2);
        if(i % 3 == 0 || i == n - 1){
            printf("%d\n",num2 - num1);
        }else{
            printf("%d ",num2 - num1);
        }
        num1 = num2;
    }
    return 0;
}