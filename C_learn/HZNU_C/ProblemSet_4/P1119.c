#include<stdio.h>
#include<string.h>
int main(){
    char input[1001];
    while(gets(input)){
        int len = strlen(input);
        for(int i = len / 2; i >= 1;i--){
            int j;
            if(i % 2 == 1){
                char num = input[i - 1];
                for(j = 2 * i;j <= len;j += i)
                    input[j - i - 1] = input[j - 1];
                input[j - i - 1] = num;
            }else {
                char num = input[(len / i) * i - 1];
                for(j = (len / i) * i; j > i;j -= i)
                    input[j - 1] = input[j - i - 1];
                input[j - 1] = num;
            }
        }
        printf("%s\n",input);
    }
    return 0;
}
