#include<stdio.h>
int main(){
    char str[300];
    while(scanf("%s", &str) != EOF) {
        if(str[0] == 'Q'||str[0] == 'q') {
            printf("%s\n", str);
        }
    }
}