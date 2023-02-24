#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        char ch[100000];
        char str[] = {"print"};
        int num = 0;
        int k = 0;
        gets(ch);
        for(int i = 0; i < strlen(ch);i++){
            if(str[num] == ch[i] && num != 5){
                num++;
            }
            printf("%c",ch[i]);
            if(num == 5 && k == 0){
                if(ch[i + 1] != ' '){
                    k = 2;
                }else {
                    k = 1;
                    printf("(");
                    i++;
                }
            }
        }
        if(k == 1) printf(")");
        printf("\n");
    }
}