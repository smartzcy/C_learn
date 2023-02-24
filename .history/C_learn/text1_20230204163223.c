#include <stdio.h>
int main() {
    int a, b;
    a = 3;
    a += a -= a * a;
    printf("%d", a);
}