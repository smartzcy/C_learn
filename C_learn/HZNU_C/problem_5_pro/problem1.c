#include<stdio.h>
int main(){
    char x,y;
    while(scanf("%c",&x) != EOF){
        if (x != y)
        {
            printf("%c",x);
        }
        y = x;
    }
}