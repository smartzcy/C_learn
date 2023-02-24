#include<stdio.h>
int main(){
    char str;
    int num = 0;
    while (scanf("%c",&str) != EOF)
    {   
        if(str >= 'a' && str <='z' || str >= 'A' && str <= 'Z'){
            num++;
        }
    }
    printf("%d",num);
    return 0;
}