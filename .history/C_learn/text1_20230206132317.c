#include <stdio.h>
int main() {
    int a = -3, b = 7, c = -1;
    printf("%d", (a == 0) && (a = a % b < b / c));
}