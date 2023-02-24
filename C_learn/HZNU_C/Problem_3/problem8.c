#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int m1 ,m2 ,m3;
        long long max,min;
        max = 0;
        min = 0;
        scanf("%d %d %d",&m1,&m2,&m3);
        min = min + 300 * (m1 + (-1 + m1) * m1);
        min = min + 100 * (m2 + (m1 * 2 + m2 -1) * m2);
        min = min + 50 * (m3 + (m1 *2 + m2 *2 + m3 -1) * m3);
        max = max + 50 * (m3 + (-1 + m3) * m3);
        max = max + 100 * (m2 + (m3 * 2 + m2 -1) * m2);
        max = max + 300 * (m1 + (m3 * 2 + m2 * 2 + m1 -1) * m1);
        printf("%lld %lld\n",min,max);
    }
}