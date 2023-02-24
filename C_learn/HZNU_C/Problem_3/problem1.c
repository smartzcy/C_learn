#include<stdio.h>
#include<math.h>
int main(){
    while(1) {
        int n;
        scanf("%d",&n);
        if(n==0) break;
        printf("%.2f\n",100.00 * pow(0.7,n));
    }
}