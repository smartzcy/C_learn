#include<stdio.h>
#include<string.h>
int main(){
    char str[1000];
    scanf("%s", str);
    for(int i=0; i<strlen(str); i++){
        if(str[i] == '.'){
            if(str[i+1] == 'd'){
                printf("Word");
            }else if (str[i+1] == 'x'){
                printf("Excel");
            }else if (str[i+1] == 'p'){
                printf("PowerPoint");
            }
            break;
        }
    }
}