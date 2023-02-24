#include<stdio.h>
int main(){
    int n;
    int num[100];
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        for (int i = n -1; i >= 0; i--){
            if(i != 0){
                printf("%d ", num[i]);
            }else{
                printf("%d\n", num[i]);
            }
        }
    }
}