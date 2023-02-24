#include<stdio.h>
int main(){
    int n ,m;
    scanf("%d %d",&n,&m);
    int num[100001] = {0};
    for(int i = 0;i < m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        num[a] = b;
    }
    for(int i = 1;i <= n;i++){
        if(num[i] == 0){
                
        }
    }
    int x ,y;
    scanf("%d %d",&x,&y);
    if(x == y){
        printf("can I win the game?");
    }else if (num[x] == y){
        printf("wait for me, my dear!");
    }else if(num[y] == x){
        printf("change! change! change!");
    }
    
}