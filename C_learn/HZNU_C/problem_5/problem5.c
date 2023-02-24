#include<stdio.h>
int max(int *p){
    int i,*p1 = p;
    int sum = *p1;
    for(i=1;i<10;i++){
        p1 = p + i;
        if(*p1 > sum){
            sum = *p1;
        }
    }
    return sum;
}
int min(int *p){
    int i,*p1 = p;
    int sum = *p1;
    for(i=1;i<10;i++){
        p1 = p + i;
        if(*p1 < sum){
            sum = *p1;
        }
    }
    return sum;
}
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
    for(int i=0; i<10; i++) scanf("%d", &a[i]);
    printf("%d %d %.2lf",max(a),min(a),average(a));
}