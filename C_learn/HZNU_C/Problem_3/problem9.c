#include<stdio.h>
int main(){
    int N;
    while (scanf("%d", &N) != EOF)
    {
        printf("%d", N);
        if(N / 100 == 0){
            printf("ss");
        }else{
            printf("rd");
        }
        N = N % 100;
        if(N / 10 == 1 || N / 10 == 5 || N / 10 == 9){
            printf("nd");
        }else {
            printf("ss");
        }
        N = N % 10;
        if(N == 3 || N == 7 || N == 2){
            printf("st");
        }else{
            printf("ss");
        }
        printf("\n");
    }
    
}