#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    int n;
    char tableware[4][12] = {"bowl","knife","fork","chopsticks"};
    while (~scanf("%d",&n)){
        int flag = 1;
        for(int i = 0 ; i < n;i++){
            char str[12];
            scanf("%s",str);
            for(int j = 0 ; j < 4;j++){
                if(strcmp(str,tableware[j]) == 0){
                    if(flag){
                        printf("%s",str);
                        flag = 0;
                    }
                    else printf(" %s",str);
                }
            }
        }
        printf("\n");
    }
    
}