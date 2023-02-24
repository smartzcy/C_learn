#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char str[10000];
    int str1[10000];
    int str2[10000];
    while (scanf("%s", &str) != EOF)
    {
        int n1 = 0;
        int n2 = 0;
        for(int i = 0; i < strlen(str); i++){
            if(str[i] == 'A' && str[i+1] == 'B'){
                str1[n1] = i;
                n1++;
            }else if(str[i] == 'B' && str[i+1] == 'A'){
                str2[n2] = i;
                n2++;
            }
        }
        int k = 0;
        for(int i = 0; i < n1;i++){
            for(int j = 0; j < n2;j++){
                if(abs(str1[i] - str2[j]) > 1){
                    k = 1;
                }
            }
        }
        if(k){
            printf("yu ye sa wang dai xing\n");
        }else printf("zhen shi ou ba\n");
    }
}