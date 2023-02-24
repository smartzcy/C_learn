#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main(){
    int r;
    scanf("%d",&r);
    printf("圆的面积为: %lf\n",pow(r , 2) * PI);
    return 0;
}