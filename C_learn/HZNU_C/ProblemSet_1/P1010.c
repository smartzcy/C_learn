#include<stdio.h>
int heng1 = 2;
int heng(int n){
    int num = heng1;
    int number = 0;
    for(int i = 1; i < n;i++){
        number += num;
        num++;
    }
    return number;
}
int lie(int n){
    int num = 1;
    int number = 0;
    for(int i = 1; i < n;i++){
        number += num;
        num++;
    }
    return number;
}
int main(){
    int N;
    while (scanf("%d",&N) != EOF)
    {
        heng1 = 2;
        for(int i = 1; i <= N;i++){
            for(int j = 1;j <= N - i + 1;j++){
                if(j != N - i + 1){
                    printf("%d ",1 + heng(j) + lie(i));
                }else{
                    printf("%d\n",1 + heng(j) + lie(i));
                }
            }
            heng1++;
        }
    }
    return 0;
}