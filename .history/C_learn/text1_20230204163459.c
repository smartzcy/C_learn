#include <stdio.h>
int main() {
    int a = 3;
    // a += a -= a * a;
    a += a -= 1;
    printf("%d", a);
}