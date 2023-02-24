#include <stdio.h>
int main() {
    int k = 1, x = 1, y = 1, z = 1;
    k = x++ && y++ || z++;
    printf("%d %d %d %d", k, x, y, z);
}