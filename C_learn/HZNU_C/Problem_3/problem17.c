#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num;
    num = 0;
    while (n != 1)
    {
        if (n % 2 == 0){
            n = n / 2;
        }else {
            n = n * 3 + 1;
        }
        num++;
    }
    printf("%d",num);
}