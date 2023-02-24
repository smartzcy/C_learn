#include <stdio.h>
int main() {
    int a = 1234;
    a = a & 377;
    printf("%d", a);
}