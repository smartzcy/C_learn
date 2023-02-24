#include<stdio.h>
#include<string.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int num = 0;
        char *str;
        for(int i=0; i<n; i++){
            scanf("%s",str);
            if(strlen(str) == 4){
                num++;
            }

        }
        printf("%d\n", num);
    }
}