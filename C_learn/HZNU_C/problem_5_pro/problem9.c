#include<stdio.h>
#include<string.h>
int main(){
    char str1[100000];
    char str2[100000];
    int N;
    while(scanf("%s", str1) !=EOF){
        scanf("%s", str2);
        scanf("%d", &N);
        for(int i = 0; i < strlen(str2); i++){
            if(i == N) printf("%s", str1); 
            printf("%c", str2[i]);
        }
        if(N == strlen(str2)) printf("%s", str1);
        printf("\n");
    }
}