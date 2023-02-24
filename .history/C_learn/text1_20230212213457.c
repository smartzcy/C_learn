#include <stdio.h>
int main() {
    int a;
    printf("%d", (a = 4 * 5, a * 2), a + 6);
}