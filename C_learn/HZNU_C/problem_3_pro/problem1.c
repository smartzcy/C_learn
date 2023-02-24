#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int num;
        num = 0;
        while(n != 0){
            if(num == 0){
                num = n % 10;
                n /= 10;
            }else{
                num = num + n % 10;
                n /= 10;
                if(num / 10 != 0){
                    num = num / 10 + num % 10;
                }
            }
        }
        printf("%d\n",num);
    }
}