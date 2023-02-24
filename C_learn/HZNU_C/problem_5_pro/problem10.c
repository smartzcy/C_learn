#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str1[25],str2[25];
    while (scanf("%s",str1) != EOF)
    {
        scanf("%s",str2);
        int x = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
        for(int i = 0; i < x; i++){
            printf("%c%c",str1[i],tolower(str2[i]));
        }
        printf("\n");
    }
}