#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        char str[101];
        gets(str);
        for(int i = strlen(str) - 1; i >= 0;i--){
            printf("%c",str[i]);
        }
        printf("\n");
        if(T) printf("\n");
    }
    return 0;
}