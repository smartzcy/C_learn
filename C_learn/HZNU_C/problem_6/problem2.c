#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,k;
        scanf("%d %d",&n,&k);
        int num;
        int j;
        for(j=0;j<n;j++){
            scanf("%d",&num);
            if(num == k){
                printf("madan\n");
                break;
            }
        }
        if(j == n)printf("why am I so diao\n");
    }
}