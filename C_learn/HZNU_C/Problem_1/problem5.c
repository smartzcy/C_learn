#include<stdio.h>
int main(){
    int num = 0;
    char str[10];
    gets(str);
    for(int i = 0; i < 10 ; i++){
        if(str[i] == 'A'){
            num = num + 1;
        }else if(str[i] == 'B'){
            num = num + 2;
        }else if(str[i] == 'C'){
            num = num + 3;
        }else if(str[i] == 'D'){
            num = num + 4;
        }
    }
    printf("%d",num);
}