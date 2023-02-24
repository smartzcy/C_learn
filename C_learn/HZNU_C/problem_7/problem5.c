#include<stdio.h>
int main(){
    int n;
    char str[100][100];
    int num[100];
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d",&str[i],&num[i]);
    }
    for(int i = 0; i < 10;i++){
        int k = 0;
        for(int j = 1; j < n;j++){
            if(num[k] > num[j] && num[j] != 0 || num[k] == 0) k = j;
        }
        num[k] = 0;
    }
    for(int i = 0; i < n;i++){
        if(num[i] != 0){
            if(i != n - 1){
                printf("%s ",str[i]);
            }else{
                printf("%s\n",str[i]);
            }
        }
    }
}