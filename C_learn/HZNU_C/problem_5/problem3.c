#include<stdio.h>

void swap(double *x, double *y){
    double s;
    s = *x;
    *x = *y;
    *y = s;
}
int main(){
    double a[3];
    double *p1,*p2,*p3;
    while(scanf("%lf",&a[0])!= EOF) {
        scanf("%lf",&a[1]);
        scanf("%lf",&a[2]);
        p1 = &a[0];
        p2 = &a[1];
        p3 = &a[2];
        if(a[0] > a[1])swap(p1,p2);
        if(a[0] > a[2])swap(p1,p3);
        if(a[1] > a[2])swap(p2,p3);
        for(int i=0; i<3; i++){
            printf("%.1lf",a[i]);
            if(3 != i)printf(" ");
        }
        printf("\n");
    }
}