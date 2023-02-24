#include<stdio.h>
int main(){
    long long num1 = 0;
    long long num2 = 0;
    for(int i=0; i<10;i++){
        long long n;
        scanf("%lld",&n);
        num1 += n;
    }
    for(int i=0; i<10; i++){
        long long n;
        scanf("%lld",&n);
        num2 += n;
    }
    if(num1 / 10.0 >= num2 / 10.0){
        printf("why am i so diao?");
    }else{
        printf("cjc died!");
    }
}