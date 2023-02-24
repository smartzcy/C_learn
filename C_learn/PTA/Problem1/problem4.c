#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int foot = n / 30.48;
    int inch = (n - foot * 30.48)/30.48*12;
    printf("%d %d",foot,inch);
}