#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){ 
        int money, m;
        scanf("%d %d",&money,&m); ;
        printf("%.2f\n",(double)money/m);
    }
}