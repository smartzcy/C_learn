#include<stdio.h>
int main(){
    int n;
    while (scanf("%d",&n), n != 0)
    {
        int num = 0;
        int number;
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&number);
            num += number;
        }
        printf("%d\n",num);
    }
    return 0;
}