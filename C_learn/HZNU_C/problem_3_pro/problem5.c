#include<stdio.h>
#include<math.h>
int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= 2 * n - 1; i++){
            printf(" ");
            for(int j = 1; j <= 2 * n - 1; j++){
                if(abs(j - n) + abs(i - n) < n){
                    printf("%d", n - abs(j - n) - abs(i - n));
                }else if(j <= n){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}