#include<stdio.h>
int pig(int n){
    if(n == 1)return 1;
    if(n == 2)return 2;
    return pig(n - 1) + pig(n - 2);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        printf("%d\n",pig(N));
    }
}