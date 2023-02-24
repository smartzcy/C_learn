#include<stdio.h>
int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int num;
        for(int i = 0; i < n; i++) {
            int m = 0;
            scanf("%d", &m);
            if(m % 2 != 0) {
                num = num + m;
            }
        }
        printf("%d\n", num);
        num = 0;
    }
}