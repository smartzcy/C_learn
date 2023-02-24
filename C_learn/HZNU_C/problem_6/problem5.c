#include<stdio.h>
int main(){
    int T;
    while(scanf("%d", &T) != EOF) {
        int n;
        int num = 0;
        for(int i = 0; i < T; i++) {
            scanf("%d", &n);
            num+=n;
        }
        printf("%.2lf\n",(double)num/T);
    }
}