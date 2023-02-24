#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long min, max, sum;
    min = 0;
    max = 0;
    sum = 0;
    for(int i=0; i<n; i++){
        long long num;
        scanf("%lld",&num);
        if (min == 0)
        {
            min = num;
            max = num;
        }
        if (max < num){
            max = num;
        }
        if (min > num){
            min = num;
        }
        sum = sum + num;
    }
    printf("%lld %lld %.1f",max,min,(float)sum / n);
}