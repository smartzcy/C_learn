#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++)
    {
        int N,fee;
        scanf("%d",&N);
        if(N < 150){
            fee = N;
        }else if(N <= 200 || N >= 300){
            fee = N % 50;
        }else{
            fee = N - 200;
        }
        printf("%d\n",fee);
    }
    return 0;
}