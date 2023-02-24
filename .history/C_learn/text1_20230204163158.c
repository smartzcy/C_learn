#include <stdio.h>
int main() {
    int a, b;
    a = 2;
    a += a -= a * a;
    printf("%d", a);
}