#include<stdio.h>
int main(){
    char str[100];
    while(scanf("%s", str) != EOF){
        printf("%s\n",str);
        if(getchar() == '\n'){
            printf("\n");
        }
    }
}