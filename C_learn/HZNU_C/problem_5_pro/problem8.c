#include<stdio.h>
int ways(int n){
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    return ways(n - 1) + ways(n - 2) + ways(n - 3);
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int n;
        scanf("%d",&n);
        printf("%d\n",ways(n));
    }
}