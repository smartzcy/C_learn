#include<stdio.h>
#include<math.h>
int main(){
    long n;
    while (scanf("%ld", &n) != EOF)
    {
        double x;
        x = 0;
        for (int i = 1; i <= n; i++){
            x = x + pow(-1,i + 1) / (double)(2 * i - 1);
        }
        printf("%.5lf\n", x);
    }
}