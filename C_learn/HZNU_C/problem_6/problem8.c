#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    char str[30][30];
    for(int i=0; i<T; i++){
        scanf("%s",&str[i]);
    }
    for(int i = 0;i < strlen(str[0]); i++){
        char a = str[0][i];
        for(int j = 1;j < T;j++){
            if(a != str[j][i]){
                printf("%d",i);
                return 0;
            }
        }
    }
}