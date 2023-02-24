#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    char str;
    int num = 1;
    getchar();
    while (scanf("%c",&str) != EOF)
    {
        if(str == '\n'){
            printf("\n");
            num++;
        }
        if(num > n){
            if(str == ' '){
                printf("\n");
                printf("\n");
            }else{
                printf("%c",str);
            }
        }else{
            printf("%c",str);
        }
    }
}