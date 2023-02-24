#include<stdio.h>
double average(int *p){
    int i,*p1 = p;
    int sum = 0;
    for(i=0;i<10;i++){
        p1 = p + i;
        sum += *p1;
    }
    return sum / 10.0;
}
int main(){
    int a[10];
    while(scanf("%d", &a[0]) != EOF) {
        for(int i = 1; i < 10; i++){
            scanf("%d", &a[i]);
        }
        printf("%.2lf\n", average(a));
    }
}