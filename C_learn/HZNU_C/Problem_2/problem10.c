#include<stdio.h>
int main(){
    int time;
    scanf("%d",&time);
    int h , min ;
    h  = time / 3600;
    time = time % 3600;
    min = time / 60;
    time = time % 60;
    printf("%d %d %d",h,min,time);
}