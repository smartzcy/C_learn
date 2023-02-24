#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        int n;
        scanf("%d",&n);
        if(n % 6 == 0){
            printf("%d divisible by 2 and 3? 1\n",n);
            printf("%d divisible by 2 or 3? 1\n",n);
            printf("%d divisible by 2 or 3, but not both? 0\n",n);
        }else if(n % 2 == 0 || n % 3 == 0){
            printf("%d divisible by 2 and 3? 0\n",n);
            printf("%d divisible by 2 or 3? 1\n",n);
            printf("%d divisible by 2 or 3, but not both? 1\n",n);
        }else{
            printf("%d divisible by 2 and 3? 0\n",n);
            printf("%d divisible by 2 or 3? 0\n",n);
            printf("%d divisible by 2 or 3, but not both? 0\n",n);
        }
    }
}