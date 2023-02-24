#include<stdio.h>
#include<math.h>

double happy(double x, double y, double z, double a, double b, double c, double d){
    return fabs(x * a + y * b + z * c + d)/sqrt(a * a + b * b + c * c);
}

int main() {

    double x, y, z, a, b, c, d;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf", &x, &y, &z, &a, &b, &c, &d) != EOF) {
        printf("%.2lf ", happy(x, y, z, a, b, c, d));
    }
    return 0;
}