#include<stdio.h>
#include<string.h>
int main(){
    char num[1000];
    gets(num);
    if(strlen(num) > 10){
        printf("BAD");
    }else{
        printf("GOOD"); 
    }
}