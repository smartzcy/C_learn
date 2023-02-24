#include<stdio.h>
int main(){
    int N;
    while (scanf("%d",&N), N != 0)
    {
        int num[1001] = {0};
        int number = 0;
        for(int i = 0; i < N;i++){
            int n;
            scanf("%d",&n);
            if(num[n] == 0){
                num[n] = 1;
                number++;
            }
        }
        printf("%d\n",number);
        int m = 1;
        for(int i = 1;i <= 1000;i++){
            if(num[i]){
                if(m++ != number){
                    printf("%d ",i);
                }else{
                    printf("%d\n",i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}