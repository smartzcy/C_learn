#include<stdio.h>
#include<string.h>
int main(){
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N;i++){
        int problem = 0;
        char answers[100][20];
        char direction[100][20];
        char str;
        while (scanf("%c",&str),str != '\n');
        char *str1;
        scanf("%s",&str1);
        problem++;
        for(int i = 0; i < strlen(str1);i++){
            if(str1[i] == '|'){
                
                problem++;
            }else{
                strcat(answers[problem],str1[i]);
            }
        }
        char *str2;
        if(str2[0] == 'T'){
            
        }
    }
}