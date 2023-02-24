#include<stdio.h>
int IfLucky(int num){
    int x = 0;
    while (num > 0)
    {   
        x++;
        int n = num % 10;
        if (n != 4 && n != 7){
            return 0;
        }
        num /= 10;
    }
    return x;
}
int main(){
    int n;
    scanf("%d",&n);
    int k = IfLucky(n);
    if(k != 0){
        if(IfLucky(k)!=0){
            printf("YES");
        }else{
            printf("NO");
        }
    }else{
        printf("NO");
    }
}