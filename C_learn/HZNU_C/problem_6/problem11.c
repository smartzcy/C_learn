#include<stdio.h>
#include<string.h>
int main(){
    char str[1000];
    scanf("%s",&str);
    int n;
    scanf("%d",&n);
    for(int i = n;i < strlen(str);i++){
        printf("%c",str[i]);
    }
}