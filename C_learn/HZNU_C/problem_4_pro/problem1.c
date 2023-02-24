#include<stdio.h>
#include<string.h>
int main(){
    char str[500];
    while (scanf("%s", str) != EOF)
    {
        for(int i=strlen(str) - 1; i>=0; i--){
            printf("%c", str[i]);
        }
        printf(" ");
    }
}