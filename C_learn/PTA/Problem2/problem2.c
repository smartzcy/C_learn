#include<stdio.h>
int main(){
    int start , end;
    scanf("%d %d",&start,&end);
    int time = (end / 100 * 60 + end % 100) - (start / 100 * 60 + start % 100);
    printf("%02d:%02d",time / 60,time % 60);
}