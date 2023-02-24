#include<stdio.h>
#include<math.h>

double happy(double a);
double a;

int main() {
    while (scanf("%lf", &a) != EOF) {
        printf("%.6lf ", happy(a));
    }
    return 0;
}
double happy(double a) {
    return sqrt(a);
}