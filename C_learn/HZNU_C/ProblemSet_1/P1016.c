#include<stdio.h>
int main(){
    char str;
    int num1 = 0;
    int num2 = 0;
    while (scanf("%c",&str),str != 'p')
    {
        if(str == '\n'){
            if(num1 == num2)printf("paired\n");
            else printf("unpaired\n");
            num1 = 0;
            num2 = 0;
        }
        if(str == '{') num1++;
        if(str == '}') num2++;
    }
    return 0;
}