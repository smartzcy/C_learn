#include <stdio.h>
int main() {
    int a, b;
    b = (a = 3 * 5, a * 4);
    printf("%d", b);
}