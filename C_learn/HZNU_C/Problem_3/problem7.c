#include<stdio.h>
#include<math.h>
int main(){
    int a , b;
    scanf("%d",&a);
    scanf("%d",&b);
    for (int i = a; i <= b; i++)
    {
        int j;
        int k = (int)sqrt((double)i);
        for (j = 2; j <= k; j++){
            if (i % j == 0){
                break;
            }
        }
        if(j > k){
            printf("%d\n",i);
        }
    }
}