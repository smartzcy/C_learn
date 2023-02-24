#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char name[20];
        char str[1000];
        scanf("%s",&name);
        getchar();
        gets(str);
        for(int i=0; i<strlen(str); i++){
            if(str[i]==name[0]){
                int j;
                for(j = 1; j < strlen(name); j++){
                    if(str[i + j]!=name[j]){
                        printf("%c",str[i]);
                        break;
                    }
                }
                if(j == strlen(name)){
                    printf("doctorZ");
                    i = i + strlen(name) - 1;
                }
            }else printf("%c", str[i]);
        }
        printf("\n");
    }
}