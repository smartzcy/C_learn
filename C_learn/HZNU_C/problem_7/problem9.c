#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int num = 0;
        int t;
        scanf("%d", &t);
        for (int i = 0; i < t; i++) {
            int number;
            scanf("%d",&number);
            num = num ^ number;
        }
        printf("%d\n",num);
    }
}