#include<stdio.h>
#include<string.h>
int main(){
    char *str[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int T;
    scanf("%d",&T);
    getchar();
    while (T--){
        char number[20];
        gets(number);
        for(int i = 0; i < strlen(number); i++){
            if(number[i] <= '9' && number[i] >= '0'){
                if(i != strlen(number) - 1){
                    printf("%s ",str[number[i] - 48]);
                }else{
                    printf("%s\n",str[number[i] - 48]);
                }
            }
        }
    }
}