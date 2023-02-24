#include<stdio.h>
int max(int x,int y){
    return x > y ? x : y;
}
int main(){
    int x,y;
    int (*pfun)(int x, int y);
    pfun = max;
    while (scanf("%d%d",&x,&y)!=EOF) 
    {
        printf("%d\n",pfun(x,y));
    }
    
}