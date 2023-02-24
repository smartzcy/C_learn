#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        int n,num;
        scanf("%d",&n);
        num = 0;
        num = n / 100;
        n = n % 100;
        num = num + n / 50;
        n = n % 50;
        num = num + n / 10;
        n = n % 10;
        num = num + n / 5;
        n = n % 5;
        num = num + n;
        printf("%d\n",num);
    }
}