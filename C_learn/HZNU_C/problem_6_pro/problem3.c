#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        char str[50][50];
        for(int i = 0; i < n; i++){
            scanf("%s",&str[i]);
        }
        char max[50];
        strcpy(max,str[0]);
        for(int i = 1; i < n; i++){
            if(strcmp(max,str[i])<0 && strlen(max) == strlen(str[i]) || strlen(max) < strlen(str[i])){
                strcpy(max,str[i]);
            }
        }
        printf("%s\n",max);
    }
    
}