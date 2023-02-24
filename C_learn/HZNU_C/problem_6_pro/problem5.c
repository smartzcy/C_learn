#include<stdio.h>
#include<math.h>
int main(){
    int n,num = 0;
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++){
        char c;
        scanf("%c",&c);
        if(c == '0') num++;
    }
    printf("%d\n", abs(n - num * 2));
}