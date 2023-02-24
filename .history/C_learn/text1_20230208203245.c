#include <stdio.h>
int main() {
    int a = 1234;
    a = a & 0377;
    printf("%d", a);
}