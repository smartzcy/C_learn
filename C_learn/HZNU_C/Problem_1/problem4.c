#include<stdio.h>
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        if(i == 0 || i == n-1){
            for(int j=0;j<m;j++) printf("*");
        }else {
            for(int j=0;j<m;j++){
                if (j == 0 || j == n-1){
                    printf("*");
                }else printf(" ");
            }
        }
        printf("\n");
    }
}