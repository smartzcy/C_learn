#include<stdio.h>
long long a[67];
void way(void){
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    a[4] = 8;
    for(int i = 5; i <= 66;i++){
        a[i] = a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4];
    }
}
int main(){
    int T;
    scanf("%d",&T);
    way();
    while (T--)
    {   
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}