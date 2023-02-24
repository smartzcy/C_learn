#include<stdio.h>
#include<string.h>
int main(){
    char a[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
    char ch;
    int i;
    while (scanf("%c",&ch)!=EOF){
        for(i = 1;i<strlen(a);i++)
            if(ch == a[i]){
                printf("%c",a[i - 1]);
                break;
            }
        if(i == strlen(a)) printf("%c",ch);
    }
    return 0;
}