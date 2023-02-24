#include <stdio.h>
int main() {
    int a = 1;
    a += a -= a * a;
    printf("%d", a);
}