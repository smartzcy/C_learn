#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int s = n / 7, f = 0;
    if((n - 7 * s) % 4 == 0){
        f = (n - 7 * s) / 4;
    }else{
        while(s--){
            if((n - 7 * s) % 4 == 0){
                f = (n - 7 * s) / 4;
                break;
            }
        }
    }
    if(n == 0 || s == -1) printf("-1");
    for(int i = 0; i < f; i++) printf("4");
    for(int i = 0; i < s; i++) printf("7");
}