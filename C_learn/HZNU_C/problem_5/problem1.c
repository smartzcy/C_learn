#include<stdio.h>
int main(){
    char *str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int n;
    while(scanf("%d", &n) != EOF){
        if(n > 12){
            printf("Oh my God!\n");
        }else{
            printf("%s\n",str[n - 1]);
        }
    }
}